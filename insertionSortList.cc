#include "listnode.hh"
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head==nullptr)
            return head;
        ListNode helper = ListNode(0);
        ListNode *cur = head;
        ListNode *pre = &helper;
        ListNode *next = nullptr;
        while(cur) {
            next = cur->next;
            while (pre->next!=nullptr && pre->next->val < cur->val) {
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            pre = &helper;
            cur = next;
        }
        return helper.next;
    }
};
int main(void) {
    Solution sl;
}
