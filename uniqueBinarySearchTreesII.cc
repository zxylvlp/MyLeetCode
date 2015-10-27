#include <vector>
#include "TreeNode.hh"
using namespace std;
class Solution {
    public:
        vector<TreeNode*> generateTrees(int n) {
            return backtrack(1,n);

        }

        vector<TreeNode*> backtrack(int start, int end) {
            vector<TreeNode*> res;
            if (start>end) {
                res.push_back(nullptr);
                return res;
            }


            for (int i=start; i<=end; i++) {
                auto left = backtrack(start,i-1);
                auto right = backtrack(i+1, end);
                for (int j=0; j<left.size(); j++) {
                    for (int k=0; k<right.size(); k++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[i];
                        root->right = right[j];
                        res.push_back(root);
                    }
                }

            }
            return res;
        }
};

int main(void) {
    Solution sl;
    vector<TreeNode*> res = sl.generateTrees(3);
}
