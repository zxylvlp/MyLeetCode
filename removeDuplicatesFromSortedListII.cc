#include "listnode.hh"
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode dummy(0);
            dummy.next = head;
            ListNode *p = &dummy;
            ListNode *p1 = head;
            ListNode *p2 = head;
            while (p1) {
                while (p2->next && p1->val==p2->next->val) {
                    p2 = p2->next;
                }

                if (p1==p2) {
                    p = p1;
                } else {
                    p->next = p2->next;
                }

                p1 = p2 = p->next;
            }

            return dummy.next;

        }
};

int main(void) {
    Solution sl;
    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(1);
    ListNode n4(1);
    ListNode n5(1);
    ListNode n6(1);
    ListNode n7(2);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    printList(&n1);
    auto res = sl.deleteDuplicates(&n1);
    printList(res);
}
