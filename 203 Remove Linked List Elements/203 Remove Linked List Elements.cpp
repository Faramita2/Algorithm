#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		
		ListNode* prev = dummy;
		ListNode* p = prev->next;


		while (p != nullptr) {
			if (p->val == val) {
				prev->next = p->next;
				delete p;
				p = prev->next;
			}
			else {
				prev = p;
				p = p->next;
			}
		}

		ListNode* newHead = dummy->next;
		delete dummy;
		return newHead;
	}
};

int main()
{
	Solution s;
	ListNode head(1);
	s.removeElements(&head, 6);
	return 0;
}