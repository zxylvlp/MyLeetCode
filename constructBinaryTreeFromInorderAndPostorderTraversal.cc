#include "TreeNode.hh"
#include <vector>
using namespace std;
class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return helper(postorder.size()-1, 0, inorder.size()-1, postorder, inorder);
        }

        TreeNode* helper(int postEnd, int inStart, int inEnd,vector<int>& postOrd, vector<int>& inOrd) {
            if (postEnd<0 || inStart>inEnd)
                return nullptr;
            TreeNode *root = new TreeNode(postOrd[postEnd]);
            int inIndex = 0;
            for (int i=inStart; i<=inEnd; i++) {
                if (inOrd[i]==postOrd[postEnd]) {
                    inIndex = i;
                    break;
                }
            }
            root->right = helper(postEnd-1, inIndex+1, inEnd, postOrd, inOrd);
            root->left = helper(postEnd-(inEnd-inIndex)-1, inStart, inIndex-1, postOrd, inOrd);
            return root;
        }
};

int main(void) {
    Solution sl;
}
