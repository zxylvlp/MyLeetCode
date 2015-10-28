#include <iostream>
#include <vector>
#include <deque>
#include "TreeNode.hh"
using namespace std;
class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
            vector<vector<int>> res;
            if (root==nullptr)
                return res;
            deque<TreeNode*> deq;
            vector<int> row;
            deq.push_front(root);
            int direct = true;
            while(!deq.empty()) {
                int len = deq.size();
                if (direct) {
                    for (int i=0; i<len; i++) {
                        TreeNode *p = deq.front();
                        deq.pop_front();
                        row.push_back(p->val);
                        if (p->left)
                            deq.push_back(p->left);
                        if (p->right)
                            deq.push_back(p->right);
                    } 
                } else {
                    for (int i=0; i<len; i++) {
                        TreeNode *p = deq.back();
                        deq.pop_back();
                        row.push_back(p->val);
                        if (p->right)
                            deq.push_front(p->right);
                        if (p->left)
                            deq.push_front(p->left);
                    }
                }
                direct = !direct;
                res.push_back(row);
                row.clear();
            }
            return res;
        }
};

int main(void) {
    Solution sl;
}
