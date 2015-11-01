#include "TreeNode.hh"
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxRes=INT_MIN;
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxRes;
    }

    int pathSum(TreeNode *root) {
        if (root==nullptr)
            return 0;
        int left = max(0, pathSum(root->left));
        int right = max(0, pathSum(root->right));
        maxRes = max(maxRes, left+right+root->val);
        return max(left, right)+(root->val);
    }
};

int main(void) {
    Solution sl;
}
