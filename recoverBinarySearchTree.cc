#include <iostream>
#include "TreeNode.hh"
using namespace std;

class Solution {
    TreeNode *firstElement = nullptr;
    TreeNode *secondElement = nullptr;
    TreeNode *prevElement = nullptr;

    public:
        void recoverTree(TreeNode *root) {
            TreeNode dummy(INT_MIN);
            prevElement = &dummy;

            traverse(root);
            swap(firstElement->val, secondElement->val);
        }

        void traverse(TreeNode *root) {
            if (root==nullptr)
                return;

            traverse(root->left);

            if (firstElement==nullptr && prevElement->val>=root->val) {
                firstElement = prevElement;
            }

            if (firstElement && prevElement->val>=root->val) {
                secondElement = root;
            }

            prevElement = root;

            traverse(root->right);

        }

};

int main(void) {
    Solution sl;
}
