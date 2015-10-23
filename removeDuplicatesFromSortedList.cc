#include "listnode.hh"
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode *head) {
            ListNode dummy(0);
            dummy.next = head;
            ListNode *p0 = &dummy, *p1 = head;
            
            while(p1) {
                if (p1->next && p1->val==p1->next->val) {
                    p1 = p1->next;
                } else {
                    p0->next = p1;
                    p0 = p1;
                    p1 = p1->next;
                }
            }
            return dummy.next;
        }

};

int main(void) {
    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(2);
    ListNode n4(3);
    ListNode n5(3);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    printList(&n1);
    Solution sl;
    auto res = sl.deleteDuplicates(&n1);
    printList(res);
}
