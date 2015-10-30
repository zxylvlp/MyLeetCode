#include "TreeNode.hh"
#include <iostream>
using namespace std;
class Solution {
    public:
        int minDepth(TreeNode* root) {
            if (root==nullptr)
                return 0;
            return deep(root, 1);
        }

        int deep(TreeNode *root, int last) {
            if (root->left==nullptr && root->right==nullptr)
                return last;
            int res = -1;
            if (root->left)
                res = deep(root->left, last+1);
            if (root->right)
                if (res!=-1)
                    res = min(res, deep(root->right, last+1));
                else
                    res = deep(root->right, last+1);
            return res;
        }
};

int main(void) {
    Solution sl;
}
