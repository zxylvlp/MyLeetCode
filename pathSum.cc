#include <vector>
#include "TreeNode.hh"
using namespace std;
class Solution {
public:
    int sum;
    bool hasPathSum(TreeNode *root, int sum_) {
        sum = sum_;
        if (root==nullptr) {
            return false;
        }
        return traverse(root);
    }

    bool traverse(TreeNode *root) {
        if (root->left==nullptr && root->right==nullptr) {
            if (root->val == sum) {
                return true;
            } 
            return false;
        }
        sum -= root->val;
        bool res=false;
        if (root->left)
            res = traverse(root->left);
        if (res==false && root->right)
            res = traverse(root->right);
        sum += root->val;
        return res;
    }
};
int main(void) {
    Solution sl;
}
