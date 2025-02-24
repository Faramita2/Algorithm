#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {

public:
	string removeOccurrences(string s, string part) {
		int patternLength = part.length(); // �Ӵ��ĳ���
		vector<int> next = getNext(part); // ���� next ����
		stack<int> matchStack; // ���ڼ�¼��ǰƥ��״̬��ջ
		int resultIndex = 0; // ����ַ�������Ч����

		for (int i = 0; i < s.length(); ++i) {
			s[resultIndex++] = s[i]; // ����ǰ�ַ�д�����ַ���

			// ��ȡ��ǰƥ�䳤�ȣ���ջ����ȡ�����ʼ��Ϊ 0��
			int currentMatchLength = matchStack.empty() ? 0 : matchStack.top();

			// ����ƥ�䳤��
			while (currentMatchLength > 0 && part[currentMatchLength] != s[i]) {
				currentMatchLength = next[currentMatchLength - 1]; // ���˵���һ��ƥ��λ��
			}
			if (part[currentMatchLength] == s[i]) {
				++currentMatchLength; // ���ƥ��ɹ�������ƥ�䳤��
			}

			matchStack.push(currentMatchLength); // ���µ�ƥ�䳤��ѹ��ջ��

			// ���ƥ�䳤�ȵ����Ӵ����ȣ�˵���ҵ�������ƥ��
			if (currentMatchLength == patternLength) {
				resultIndex -= patternLength; // �Ƴ�ƥ�䲿��
				for (int k = 0; k < patternLength; ++k) {
					matchStack.pop(); // ���ջ�ж�Ӧ��ƥ��״̬
				}
			}
		}

		s.resize(resultIndex); // ��������ַ����ĳ���
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