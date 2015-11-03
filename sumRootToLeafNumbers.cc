#include "TreeNode.hh"
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        return helper(root, 0);
    }

    int helper(TreeNode *root, int x) {
        int tmp = 10*x + root->val;
        if (!root->left && !root->right)
            return tmp;
        int sum = 0;
        if (root->left)
            sum += helper(root->left, tmp);
        if (root->right)
            sum += helper(root->right, tmp);
        return sum;
    }
};
int main(void) {
    Solution sl;
}
