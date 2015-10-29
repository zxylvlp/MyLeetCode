#include "TreeNode.hh"
#include <algorithm>
#include <complex>
using namespace std;
class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            return isBalance(root)!=-1;
        }

        int isBalance(TreeNode* root) {
            if (root==nullptr)
                return 0;
            int leftDeep = isBalance(root->left);
            if (leftDeep==-1)
                return -1;
            int rightDeep = isBalance(root->right);
            if (rightDeep==-1)
                return -1;
            if (abs(leftDeep-rightDeep) > 1)
                return -1;
            return max(leftDeep, rightDeep) + 1;
        }
};

int main(void) {
    Solution sl;
}
