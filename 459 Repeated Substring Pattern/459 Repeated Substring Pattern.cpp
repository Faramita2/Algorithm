#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
		bool res = false;
		int len = s.size();
		for (int i = 0; i < len / 2; i++) {
			string tmp = "";
			if (len % (i+1) == 0) {
				for (int j = 0; j < len / (i+1); j++) {
					tmp.append(s.substr(0, i + 1));
				}
			}
			if (tmp == s) return true;
		}
		
		return res;
    }
	
	bool repeatedSubstringPattern_(string s) {
		string doubled = s + s;
		return doubled.substr(1, doubled.size() - 2).find(s) != string::npos;
	}
};

int main()
{
    Solution s;
	
	string s1 = "abab";
	assert(true == s.repeatedSubstringPattern_(s1));
	
	string s2 = "aba";
	assert(false == s.repeatedSubstringPattern_(s2));
	
	string s3 = "abcabcabcabc";
	assert(true == s.repeatedSubstringPattern_(s3));
	
	return 0;
}
