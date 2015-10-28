#include "TreeNode.hh"
#include <iostream>
using namespace std;
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (root==nullptr)
                return 0;
            return deep(root,0);
        }

        int deep(TreeNode *root, int last) {
            if (root==nullptr)
                return last;
            return max(deep(root->left, last+1), deep(root->right, last+1));
        }
};

int main(void) {
    Solution sl;
}
