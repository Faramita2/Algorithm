#include <iostream>

class Solution {
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;
		ListNode* next = nullptr;
		while (curr != nullptr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

	ListNode* reverseList_(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;

		ListNode* newHead = reverseList_(head->next);
		head->next->next = head;
		head->next = nullptr;

		return newHead;
	}
};

int main()
{
	Solution s;
}