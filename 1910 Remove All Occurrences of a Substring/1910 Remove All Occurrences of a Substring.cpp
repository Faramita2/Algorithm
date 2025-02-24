#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {

public:
	string removeOccurrences(string s, string part) {
		int patternLength = part.length(); // 子串的长度
		vector<int> next = getNext(part); // 计算 next 数组
		stack<int> matchStack; // 用于记录当前匹配状态的栈
		int resultIndex = 0; // 结果字符串的有效长度

		for (int i = 0; i < s.length(); ++i) {
			s[resultIndex++] = s[i]; // 将当前字符写入结果字符串

			// 获取当前匹配长度（从栈顶获取，或初始化为 0）
			int currentMatchLength = matchStack.empty() ? 0 : matchStack.top();

			// 更新匹配长度
			while (currentMatchLength > 0 && part[currentMatchLength] != s[i]) {
				currentMatchLength = next[currentMatchLength - 1]; // 回退到上一个匹配位置
			}
			if (part[currentMatchLength] == s[i]) {
				++currentMatchLength; // 如果匹配成功，增加匹配长度
			}

			matchStack.push(currentMatchLength); // 将新的匹配长度压入栈中

			// 如果匹配长度等于子串长度，说明找到了完整匹配
			if (currentMatchLength == patternLength) {
				resultIndex -= patternLength; // 移除匹配部分
				for (int k = 0; k < patternLength; ++k) {
					matchStack.pop(); // 清空栈中对应的匹配状态
				}
			}
		}

		s.resize(resultIndex); // 调整结果字符串的长度
		return s;
	}

private:
	void printVector(vector<int>& vec) {
		for (int i = 0; i < vec.size(); i++) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
		cout << endl;
	}

	vector<int> getNext(string& part) {
		// ababa
		// 00012
		int n = part.size();
		vector<int> next(n, 0);
		int j = 0;
		for (int i = 1; i < n; i++) {
			while (j > 0 && part[i] != part[j]) {
				j = next[j - 1];
			}
			if (part[i] == part[j]) {
				j++;
			}
			next[i] = j;
		}

		return next;
	}

	vector<int> getNextVal(string& part, vector<int>& next) {
		vector<int> nextVal(part.size(), 0);
		for (int i = 1; i < next.size(); ++i) {
			int j = next[i];
			if (part[i] == part[j]) {
				nextVal[i] = nextVal[j];
			}
			else {
				nextVal[i] = j;
			}
		}
		return nextVal;
	}
};

int main()
{
	Solution s;
	string res = s.removeOccurrences("daabcbaabcbc", "abc");
	cout << res << endl;
	res = s.removeOccurrences("axxxxyyyyb", "xy");
	cout << res << endl;
	//s.removeOccurrences("", "aaaaaac");
	//s.removeOccurrences("", "ababaa");

	return 0;
}