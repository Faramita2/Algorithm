#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {

public:
	string reverseWords_(string s) {
		removeExtraSpaces(s);
		reverse(s.begin(), s.end());
		reverseEachWord(s);
		return s;
	}

	string reverseWords(string s) {
		int size = s.size();
		int k = 0;
		int d = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				++k;
				if (k > 1) {
					d++;
					s[i - k + 1] = s[i];
					k -= 1;
					size--;
				}
				else {
					s[i - d] = s[i];
				}
			}
			else {
				s[i - d] = s[i];
				k = 0;
			}
		}
		if (s.front() == ' ') {
			for (int i = 1; i < size; i++) {
				s[i - 1] = s[i];
			}
			size--;
		}
		for (int i = size - 1; s[i] == ' '; i--) {
			size--;
		}
		s.resize(size);
		reverse(s.begin(), s.end());

		int start = 0;
		int end = 0;
		while (start < s.size()) {
			while (end < s.size() && s[end] != ' ') end++;
			reverse(s.begin() + start, s.begin() + end);
			start = end + 1;
			end = end + 1;
		}

		return s;
	}

private:
	void reverseEachWord(string& s) {
		int start = 0;
		for (int i = 0; i <= s.size(); ++i) {
			if (i == s.size() || s[i] == ' ') {
				reverse(s.begin() + start, s.begin() + i);
				start = i + 1;
			}
		}
	}

	void removeExtraSpaces(string& s) {
		int n = s.size();
		int write = 0; // 写入位置
		bool space = false; // 是否遇到过空格

		// 跳过开头的空格
		int read = 0;
		while (read < n && s[read] == ' ') {
			++read;
		}

		for (; read < n; ++read) {
			if (s[read] != ' ') {
				// 非空格字符直接写入
				s[write++] = s[read];
				space = false;
			}
			else if (!space) {
				// 第一个空格保留，后续连续空格跳过
				s[write++] = ' ';
				space = true;
			}
		}

		// 去除末尾可能多余的空格
		if (write > 0 && s[write - 1] == ' ') {
			write--;
		}
		s.resize(write);
	}
};

int main()
{
	Solution s;

	string s1 = "the sky is blue";
	string e1 = "blue is sky the";
	//cout << "\"" << s.reverseWords(s1) << "\"" << endl;
	//assert(s.reverseWords(s1) == e1);
	//           0123456789
	string s2 = "  hello world          ";
	string e2 = "world hello";
	//assert(s.reverseWords(s2) == e2);
	cout << "\"" << s.reverseWords_(s2) << "\"" << endl;
	//           0123456789
	string s3 = "a good   example";
	string e3 = "example good a";
	//assert(s.reverseWords(s3) == e3);
	//cout << "\"" << s.reverseWords(s3) << "\"" << endl;

	string s4 = "   fffff ff gg ee";
	//cout << "\"" << s.reverseWords(s4) << "\"" << endl;
	return 0;
}