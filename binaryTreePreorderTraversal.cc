#include "binaryTree.hh"
#include "printHelper.hh"
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;

            if (root == nullptr)
                return res;

            stack<TreeNode*> stk;
            stk.push(root);

            while(!stk.empty()) {
                TreeNode* node = stk.top();
                res.push_back(node->val);
                stk.pop();
                if (node->right)
                    stk.push(node->right);
                if (node->left)
                    stk.push(node->left);
            }

            return res;
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
