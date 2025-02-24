#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> operands;
		for (const string& s : tokens) {
			if (s.size() == 1 && !isdigit(s.front())) {
				int b = operands.top();
				operands.pop();
				int a = operands.top();
				operands.pop();
				int res;
				if (s == "+") {
					res = a + b;
				}
				else if (s == "-") {
					res = a - b;
				}
				else if (s == "*") {
					res = a * b;
				}
				else {
					res = a / b;
				}
				operands.push(res);
			}
			else {
				operands.push(stoi(s));
			}
		}

		return operands.top();
	}
};

int main()
{
	Solution s;

	vector<string> tokens1 = { "2", "1", "+", "3", "*" };
	int res1 = 9;
	assert(s.evalRPN(tokens1) == res1);

	vector<string> tokens2 = { "4","13","5","/","+" };
	int res2 = 6;
	assert(s.evalRPN(tokens2) == res2);

	vector<string> tokens3 = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	int res3 = 22;
	assert(s.evalRPN(tokens3) == res3);

	return 0;
}