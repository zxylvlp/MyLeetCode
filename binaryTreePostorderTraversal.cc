#include "binaryTree.hh"
#include "printHelper.hh"
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode*> stk;
            TreeNode *cur = root;
            TreeNode *last = nullptr;

            while (cur || !stk.empty()) {
                if (cur) {
                    stk.push(cur);
                    cur = cur->left;
                } else {
                    TreeNode *top = stk.top();
                    if (top->right && last != top->right)
                        cur = top->right;
                    else {
                        res.push_back(top->val);
                        last = top;
                        stk.pop();
                    }
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
    vector<int> res = sl.postorderTraversal(&t1);
    printVec(res);
}
