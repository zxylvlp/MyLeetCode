#include <iostream>
#include "TreeNode.hh"
using namespace std;
class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            return isValidBST(root, nullptr, nullptr);

        }
        bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {

            if (root==nullptr) {
                return true;
            }
            
            if ((max && root->val >= max->val) || (min && root->val <= min->val)) {
                return false;
            }

            return (isValidBST(root->left, min, root) && isValidBST(root->right, root, max));

        }
};
