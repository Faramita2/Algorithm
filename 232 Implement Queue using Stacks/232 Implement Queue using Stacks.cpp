#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class MyQueue {
public:
	stack<int> in;
	stack<int> out;

	MyQueue() {}

	void push(int x) {
		in.push(x);
	}

	int pop() {
		int res = peek();
		out.pop();
		return res;
	}

	int peek() {
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top());
				in.pop();
			}
		}
		return out.top();
	}

	bool empty() {
		return in.empty() && out.empty();
	}
};

int main()
{
	MyQueue* obj = new MyQueue();
	obj->push(1);
	obj->push(2);

	assert(1 == obj->peek());
	assert(1 == obj->pop());
	assert(false == obj->empty());

	return 0;
}