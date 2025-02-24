#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	string removeDuplicates(string s) {
		stack<char> st;
		string res = "";

		for (int i = 0; i < s.size(); i++) {
			if (!st.empty() && st.top() == s[i]) {
				st.pop();
			}
			else st.push(s[i]);
		}
		while (!st.empty()) {
			res += st.top();
			st.pop();
		}
		reverse(res.begin(), res.end());

		return res;
	}

	string removeDuplicates_(string s) {
		string res = "";

		for (int i = 0; i < s.size(); i++) {
			if (res.empty() || res.back() != s[i]) {
				res.push_back(s[i]);
			}
			else {
				res.pop_back();
			}
		}

		return res;
	}
};

int main()
{
	Solution s;

	string s1 = "abbaca";
	string res1 = s.removeDuplicates_(s1);
	cout << res1 << endl;

	string s2 = "azxxzy";
	string res2 = s.removeDuplicates_(s2);
	cout << res2 << endl;

	return 0;
}