#include "binaryTree.hh"
#include "printHelper.hh"
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode*> stk;

            TreeNode *cur = root;

            while(!stk.empty() || cur) {
                if (cur) {
                    stk.push(cur);
                    cur = cur->left;
                } else {
                    TreeNode *p = stk.top();
                    res.push_back(p->val);
                    stk.pop();
                    cur = p->right;
                }
            }

            return res;
        }

        

};

int main(void) {

    TreeNode t1(1),t2(2),t3(3);
    t1.right = &t2;
    t2.left = &t3;
    Solution sl;
    vector<int> res = sl.inorderTraversal(&t1);
    printVec(res);
}
