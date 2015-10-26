#include "listnode.hh"
class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode dummy0(0), dummy1(0);
            dummy1.next=head;
            ListNode *tail0 = &dummy0, *tail1 = &dummy1;
            while(tail1->next) {
                if (tail1->next->val<x) {
                    tail0->next = tail1->next;
                    tail1->next = tail1->next->next;
                    tail0 = tail0->next;
                } else {
                    tail1 = tail1->next;
                }
            }
            tail0->next = dummy1.next;
            return dummy0.next;
            
        }
};

int main(void) {
    Solution sl;

    ListNode n1(1);
    ListNode n2(4);
    ListNode n3(3);
    ListNode n4(2);
    ListNode n5(5);
    ListNode n6(2);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    printList(&n1);
    ListNode* res = sl.partition(&n1, 3);
    printList(res);
}
