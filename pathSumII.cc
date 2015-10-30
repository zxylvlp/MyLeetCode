#include <vector>
#include "TreeNode.hh"
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> row;
    int now=0;
    int sum;
    vector<vector<int>> pathSum(TreeNode* root, int sum_) {
        sum = sum_;
        if (root==nullptr) {
            return res;
        }
        traverse(root);
        return res;
    }

    void traverse(TreeNode *root) {
        if (root->left==nullptr && root->right==nullptr)
            if (now + root->val == sum) {
                row.push_back(root->val);
                res.push_back(row);
                row.pop_back();
            }
        now += root->val;
        row.push_back(root->val);
        if (root->left)
            traverse(root->left);
        if (root->right)
            traverse(root->right);
        now -= root->val;
        row.pop_back();


    }
};
int main(void) {
    Solution sl;
}
