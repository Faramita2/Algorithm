#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

class MyStack {

private:
	queue<int> data;

	int popPeek() {
		int size = data.size();
		int first = data.front();
		while (--size > 0) {
			data.push(first);
			data.pop();
			first = data.front();
		}
		data.pop();
		return first;
	}

public:
	MyStack() {}

	void push(int x) {
		data.push(x);
	}

	int pop() {
		int peek = top();
		return peek;
	}

	int top() {
		// in: 1 2 3
		// reverse:
		// 2 3 1
		// 3 1 2
		// reverse:
		// 1 2 3
		int first = popPeek();

		data.push(first);
		
		return first;
	}

	bool empty() {
		return data.empty();
	}
};

int main()
{

	MyStack* obj = new MyStack();
	obj->push(1);
	obj->push(2);
	assert(2 == obj->top());
	assert(2 == obj->pop());
	assert(false == obj->empty());

	return 0;
}