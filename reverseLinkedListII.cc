#include "listnode.hh"
class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            ListNode dummy(0);
            dummy.next = head;
            ListNode* p1 = &dummy;
            for (int i=1; i<m; i++) {
                p1 = p1->next;
            }
            ListNode *prev = p1;
            ListNode *now = prev->next;
            ListNode *nxt = now->next;
            for (int i=m; i<n; i++) {
                prev = now;
                now = nxt;
                nxt = nxt->next;
                now->next = prev;
                
            }
            p1->next->next = nxt;
            p1->next = now;
            return dummy.next;
        }
};

int main(void) {
    Solution sl;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    printList(&n1);
    auto res = sl.reverseBetween(&n1, 2, 4);
    printList(res);
}
