#include <unordered_map>
#include "RandomListNode.hh"
using namespace std;
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            unordered_map<RandomListNode*,RandomListNode*> m;
            RandomListNode* head_ = head;
            while(head_) {
                m[head_] = new RandomListNode(head_->label);
                head_ = head_->next;
            }
            head_ = head;
            while(head_) {
                m[head_]->next = m[head_->next];
                m[head_]->random = m[head_->random];
                head_ = head_->next;
            }
            return m[head];
        }
};

int main(void) {
    Solution sl;
}
