#include <iostream>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += 2 * k) {
			reverseK(s, k, i);
		}
		return s;
	}

private:
	void reverseK(string& s, int k, int start) {
		int end = min(start + k - 1, (int)s.size() - 1);
		for (int i = start, j = end; i < j; i++, j--) {
			swap(s[i], s[j]);
		}
	}
};

int main()
{
	Solution solution;
	string s = "abcdefg";
	int k = 2;

	string res = solution.reverseStr(s, k);
	cout << res << endl;

	/*string s1 = "a";
	int k1 = 2;
	string res = solution.reverseStr(s1, k1);
	cout << res << endl;*/

	return 0;
}