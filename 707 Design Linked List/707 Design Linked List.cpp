#include <iostream>
#include <vector>
using namespace std;

class MyLinkedList {

public:
	struct LinkedNode {
		int val;
		LinkedNode* next;
		LinkedNode(int val) : val(val), next(nullptr) {}
	};

	MyLinkedList() : size(0), dummy(new LinkedNode(-1)) {}

	int get(int index) {
		if (index >= size) return -1;

		LinkedNode* p = getNode(index);

		return p == nullptr ? -1 : p->val;
	}

	void addAtHead(int val) {
		LinkedNode* p = new LinkedNode(val);

		p->next = dummy->next;
		dummy->next = p;

		size++;
	}

	void addAtTail(int val) {
		LinkedNode* q = new LinkedNode(val);
		LinkedNode* p = getNode(size - 1);

		if (p == nullptr) dummy->next = q;
		else {
			p->next = q;
		}

		size++;
	}

	void addAtIndex(int index, int val) {
		if (index > size) return;

		LinkedNode* q = new LinkedNode(val);
		LinkedNode* p = getNode(index - 1);

		q->next = p->next;
		p->next = q;
		
		size++;
	}

	void deleteAtIndex(int index) {
		if (index >= size) return;

		LinkedNode* prev = getNode(index - 1);
		LinkedNode* p = prev->next;

		prev->next = p->next;
		delete p;

		size--;
	}

private:
	int size;
	LinkedNode* dummy;

	LinkedNode* getNode(int index) {
		if (index < -1) return nullptr;

		LinkedNode* curr = dummy;
		for (int i = -1; i < index && curr != nullptr; i++) {
			curr = curr->next;
		}

		return curr;
	}
};

int main()
{
	MyLinkedList* myLinkedList = new MyLinkedList();
	//myLinkedList->addAtHead(1);
	//myLinkedList->addAtTail(3);
	myLinkedList->addAtIndex(0, 10);
	myLinkedList->addAtIndex(0, 20);
	myLinkedList->addAtIndex(1, 30);
	myLinkedList->get(0);

	return 0;
}