#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
private:
	vector<int> getNext(string& match) {
		vector<int> next(match.size(), 0);
		int j = 0;
		for (int i = 1; i < match.size(); i++) {
			if (j > 0 && match[i] != match[j])
				j = next[j - 1];
			if (match[i] == match[j])
				j++;
			next[i] = j;
		}

		return next;
	}

public:
	// 	string h3 = "ababacabcabc";
	// 	string n3 = "ababa";
	// 	string h5 = "mississippi";
	//  string n5 = "issip";
	int strStr(string haystack, string needle) {
		vector<int> next = getNext(needle);

		for (int i = 0, j = 0; i < haystack.size(); i++) {
			while (j > 0 && needle[j] != haystack[i]) {
				j = next[j - 1];
			}

			if (needle[j] == haystack[i]) {
				j++;
			}

			if (j == needle.size()) return i - j + 1;
		}

		return -1;
	}
};

int main()
{
	Solution s;

	/*string h1 = "sadbutsad";
	string n1 = "sad";
	int res1 = s.strStr(h1, n1);
	assert(0 == res1);*/

	//string h4 = "aaaaa";
	//string n4 = "bba";
	//int res4 = s.strStr(h4, n4);
	//assert(-1 == res4);

	string h5 = "mississippi";
	string n5 = "issip";
	int res5 = s.strStr(h5, n5);
	assert(4 == res5);

	string h2 = "leetcode";
	// next:    -10000
	string n2 = "leeto";
	//int res2 = s.strStr(h2, n2);
	//assert(-1 == res2);

	string h3 = "ababacabcabc";
	// next:     00012
	// next:    -10123
	string n3 = "ababa";
	int res3 = s.strStr(h3, n3);
	assert(0 == res3);

	return 0;
}