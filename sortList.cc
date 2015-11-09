#include "listnode.hh"
class Solution {
    public:
        ListNode* sortList(ListNode *head) {
            if (!head||!head->next)
                return head;
            ListNode *f = head->next->next;
            ListNode *p = head;
            while (f && f->next) {
                p = p->next;
                f = f->next->next;
            }
            ListNode *h2 = sortList(p->next);
            p->next = nullptr;
            return merge(sortList(head), h2);
        }
        ListNode* merge(ListNode *h1, ListNode *h2) {
            ListNode hn = ListNode(INT_MIN);
            ListNode *c = &hn;
            while (h1 && h2) {
                if (h1->val < h2->val) {
                    c->next = h1;
                    h1 = h1->next;
                } else {
                    c->next = h2;
                    h2 = h2->next;
                }
                c = c->next;
            }
            if (h1)
                c->next = h1;
            else
                c->next = h2;
            return hn.next;
        }
};
int main(void) {
    Solution sl;
}
