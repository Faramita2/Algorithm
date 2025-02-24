#include <iostream>
using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head->next;
        ListNode* fast = slow->next;

        while (slow != fast && fast != nullptr) {
            slow = slow->next;
            fast = fast->next != nullptr ? fast->next->next : nullptr;
        }
        
        fast = head;
        while (fast != slow && fast != nullptr && slow != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main()
{
    cout << "Hello World!\n";
}