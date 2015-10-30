#include "TreeNode.hh"
class Solution {
public:
    TreeNode *prev = nullptr;
    void flatten(TreeNode* root) {
        if (root==nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
        
    }
};

int main(void) {
    Solution sl;
}
