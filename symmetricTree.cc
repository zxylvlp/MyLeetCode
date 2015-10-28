#include <iostream>
#include "TreeNode.hh"
using namespace std;

class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if (root==nullptr)
                return true;
            if (root->left==nullptr || root->nullptr)
                return root->left == root->right;
            if (root->left->val!=root->right->val)
                return false;
            stack<TreeNode*> stk;
            stk.push(root->left);
            stk.push(root->right);

            while (stk.size()!=0) {
                TreeNode *left = stk.top();
                stk.pop();
                TreeNode *right = stk.top();
                stk.pop();
                if (left==nullptr||right==nullptr)
                    if(left!=right)
                        return false;
                    else
                        continue;
                if (left->val != right->val)
                    return false;
                stk.push(left->left);
                stk.push(right->right);
                stk.push(left->right);
                stk.push(right->left);
            }
            return true;
        }
};

int main(void) {
    Solution sl;

}

