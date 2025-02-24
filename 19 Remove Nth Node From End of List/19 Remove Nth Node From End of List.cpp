#include <iostream>
using namespace std;

class Solution {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode();
		dummy->next = head;
		ListNode* prev = dummy;
		ListNode* fast = prev->next;

		while (--n > 0 && fast != nullptr) {
			fast = fast->next;
		}

		if (n == 0 && fast == nullptr) return nullptr;

		ListNode* slow = prev->next;
		while (fast->next != nullptr) {
			fast = fast->next;
			prev = slow;
			slow = slow->next;
		}
		prev->next = slow->next;
		delete slow;

		return dummy->next;
	}
};

int main()
{
	cout << "Hello World!\n";
}