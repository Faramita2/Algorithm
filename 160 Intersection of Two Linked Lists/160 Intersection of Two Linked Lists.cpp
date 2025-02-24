#include <iostream>
using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int aLen = getLen(headA), bLen = getLen(headB);
        int delta = abs(aLen - bLen);

        ListNode* p = aLen > bLen ? headA : headB;
        while (--delta >= 0) p = p->next;
        ListNode* q = aLen > bLen ? headB : headA;

        while (p != nullptr) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }

        return nullptr;
    }

    ListNode* getIntersectionNode_(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = pA != nullptr ? pA->next : headB;
            pB = pB != nullptr ? pB->next : headA;
        }

        return pA;
    }
private:
    int getLen(ListNode* head) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp != nullptr) {
            len++;
            tmp = tmp->next;
        }
        return len;
    }
};

int main()
{
    cout << "Hello World!\n";
}