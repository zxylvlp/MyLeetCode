#include "binaryTree.hh"
#include "printHelper.hh"
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> res;
        vector<int> preorderTraversal(TreeNode *root) {
            recursion(root);
            return res;
        }

        void recursion(TreeNode *node) {
            if (node != nullptr) {
                res.push_back(node->val);
                recursion(node->left);
                recursion(node->right);
            }
        }

};

int main(void) {

    TreeNode t1(1),t2(2),t3(3);
    t1.right = &t2;
    t2.left = &t3;
    Solution sl;
    vector<int> res = sl.preorderTraversal(&t1);
    printVec(res);
}
