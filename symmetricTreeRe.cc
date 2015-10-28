#include <iostream>
#include "TreeNode.hh"
using namespace std;

class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (root==nullptr)
                return true;
            return isSymmectric(root->left, root->right);
        }

        bool isSymmectric(TreeNode *left, TreeNode *right) {
            if (left==nullptr || right==nullptr)
                return left==right;
            if (left->val != right->val)
                return false;
            return isSymmectric(left->left, right->right) && isSymmectric(left->right, right->left);
        }
};

int main(void) {
    Solution sl;

}
