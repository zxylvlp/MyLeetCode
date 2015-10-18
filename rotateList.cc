#include "listnode.hh"

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if (head==nullptr)
                return head;
            ListNode* tail = head;
            int listLen = 1;
            while (tail->next!=nullptr) {
                tail = tail->next;
                listLen++;
            }

            k = k%listLen;
            if (k==0) {
                return head;
            }

            ListNode *mid = head;
            for (int i=1; i<(listLen - k); i++) {
                mid = mid->next;
            }

            tail->next = head;
            head = mid->next;
            mid->next = nullptr;

            return head;
        }
};

int main(void) {
    Solution sl;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    l1.next = &l2;
    l2.next = &l3;
    printList(&l1);
    ListNode *res = sl.rotateRight(&l1,2000000000);

    printList(res);
}
