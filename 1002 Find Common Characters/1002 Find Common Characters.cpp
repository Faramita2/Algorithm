#include <iostream>
#include <vector>
#include <cassert>
#include <limits>
using namespace std;

class Solution {
public:
	vector<string> commonChars_(vector<string>& words) {
		vector<string> res;
		vector<int> minFreq(26, INT32_MAX);

		for (const string& word : words) {
			vector<int> freq(26, 0);
			for (char c : word) {
				freq[c - 'a'] += 1;
			}
			for (int i = 0; i < 26; i++) {
				minFreq[i] = min(freq[i], minFreq[i]);
			}
		}

		for (int i = 0; i < 26; i++) {
			int n = minFreq[i];
			while (n-- > 0) {
				res.push_back(string(1, 'a' + i));
			}
		}

		return res;
	}

	vector<string> commonChars(vector<string>& words) {
		vector<string> res;
		vector<vector<int>> m(words.size());

		for (int i = 0; i < words.size(); i++) {
			vector<int> tmp(26, 0);
			for (const char c : words[i]) {
				int index = c - 'a';
				tmp[index] = tmp[index] != 0 ? ++tmp[index] : 1;
			}
			m.at(i) = tmp;
		}

		for (int i = 0; i < 26; i++) {
			int n = m[0][i];
			int count = 1;

			for (int j = 1; j < words.size(); j++) {
				n = min(n, m[j][i]);
				if (n == 0) break;
				count++;
			}

			if (count == words.size()) {
				for (int k = 0; k < n; k++) {
					res.push_back(string(1, 'a' + i));
				}
			}
		}

		return res;
	}
};

static void print(vector<string>& chars) {
	for (const string s : chars) {
		cout << s << " ";
	}
	cout << endl;
}

int main()
{
	vector<string> strings1 = { "bella","label","roller" };
	print(strings1);
	Solution s;
	vector<string> res1 = s.commonChars_(strings1);
	print(res1);
	vector<string> strings2 = { "cool","lock","cook" };
	print(strings2);
	vector<string> res2 = s.commonChars_(strings2);
	print(res2);
	return 0;
}