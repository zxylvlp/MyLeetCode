#include "listnode.hh"
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head||!head->next)
            return;
        ListNode *p1=head, *p2=head;
        while(p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode *preMiddle = p1;
        ListNode *preCurrent = p1->next;
        while(preCurrent->next) {
            ListNode *current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }

        p1=head;
        p2=preMiddle->next;
        while(p1!=preMiddle) {
            preMiddle->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMiddle->next;
        }
        
    }
};
int main(void) {
    Solution sl;
}
