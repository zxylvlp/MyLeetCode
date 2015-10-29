#include <vector>
#include <queue>
#include "binaryTree.hh"
#include "printHelper.hh"

using namespace std;

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode *root){
            vector<vector<int>> res;
            if (root==nullptr)
                return res;
            queue<TreeNode *> que;
            vector<int> row;
            que.push(root);
            while(!que.empty()) {
                int len = que.size();
                for (int i=0; i<len; i++) {
                    TreeNode *p = que.front();
                    que.pop();
                    row.push_back(p->val);
                    if (p->left) {
                        que.push(p->left);
                    }
                    if (p->right) {
                        que.push(p->right);
                    }
                }
                res.push_back(row);
                row.clear();
            }
            reverse(res.begin(), res.end());
            return res;
        }

};

int main(void) {

    TreeNode t1(3),t2(9),t3(20),t4(15),t5(7);
    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t4;
    t3.right = &t5;
    Solution sl;
    vector<vector<int>> res = sl.levelOrder(&t1);
    printMat(res);
}

