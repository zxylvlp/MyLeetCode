#include <iostream>
#include "TreeNode.hh"
using namespace std;

class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return helper(0, 0, inorder.size()-1, preorder, inorder);
        }

        TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
            if (preStart>preorder.size()-1 || inStart>inEnd) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(preorder[preStart]);
            int inIndex = 0;
            for (int i=inStart; i<=inEnd; i++) {
                if (inorder[i] == root->val)
                    inIndex = i;
            }
            root->left = helper(preStart+1, inStart, inIndex-1, preorder, inorder);
            root->right = helper(preStart+inIndex-inStart+1, inIndex+1, inEnd, preorder, inorder);
            return root;
        }
};

int main(void) {
    Solution sl;
}
