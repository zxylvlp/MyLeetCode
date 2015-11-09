#include "listnode.hh"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow==fast)
                break;
        }
        if (!fast||!fast->next)
            return nullptr;
        slow = head;
        while (slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
int main(void) {
    Solution sl;
}
