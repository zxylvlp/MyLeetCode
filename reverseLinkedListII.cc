#include "listnode.hh"
class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            for (int i=0; i<m; i++) {

            }
            
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
