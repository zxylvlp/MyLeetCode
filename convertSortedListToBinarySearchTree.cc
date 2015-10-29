#include "listnode.hh"
#include "TreeNode.hh"
using namespace std;

class Solution {
    public:
        ListNode *list;
        TreeNode* sortedListToBST(ListNode *head) {
            list = head;
            return helper(count(head));
        }

        TreeNode* helper(int n) {
            if (n==0)
                return nullptr;
            TreeNode *root = new TreeNode(0);
            root->left = helper(n/2);
            root->val = list->val;
            list = list->next;
            root->right = helper(n-n/2-1);
            return root;
        }

        int count(ListNode *head) {
            int i=0;
            while(head) {
                head = head->next;
                i++;
            }
            return i;
        }
};

int main(void) {
    Solution sl;
}
