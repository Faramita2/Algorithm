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

    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* tmp = head->next->next;
        ListNode* newHead = head->next;
        newHead->next = head;
        head->next = swapPairs(tmp);

        return newHead;
    }

    ListNode* swapPairs_(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;


        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = first->next;
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
        }
        
        return dummy->next;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}