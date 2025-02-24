#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote.size() > magazine.size()) return false;
		int m[26] = { 0 };
		for (char c : magazine) {
			int i = c - 'a';
			m[i]++;
		}
		for (char c : ransomNote) {
			int i = c - 'a';
			if (m[i] == 0 || --m[i] < 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	assert(false == s.canConstruct("a", "b"));
	assert(false == s.canConstruct("aa", "ab"));
	assert(true == s.canConstruct("aa", "aab"));

	return 0;
}