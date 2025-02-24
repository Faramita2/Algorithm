#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (char c : s) {
			if (c == '(' || c == '[' || c == '{') st.push(c);
			else if (st.empty()) {
				return false;
			}
			else {
				char top = st.top();
				st.pop();
				if ((c == ')' && top != '(') ||
					(c == ']' && top != '[') ||
					(c == '}' && top != '{')
					)
					return false;
			}
		}

		return st.empty();
	}
};

int main()
{
	Solution so;

	string s1 = "()";
	assert(true == so.isValid(s1));

	string s2 = "()[]{}";
	assert(true == so.isValid(s2));

	string s3 = "(]";
	assert(false == so.isValid(s3));

	string s4 = "([])";
	assert(true == so.isValid(s4));

	return 0;
}