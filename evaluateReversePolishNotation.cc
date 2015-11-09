#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int op1;
        int op2;
        for (int i=0; i<tokens.size(); i++) {
            string str = tokens[i];
            if (str=="+") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op1+op2);

            } else if (str=="-") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op2-op1);

            } else if (str=="*") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op1*op2);

            } else if (str=="/") {
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                stk.push(op2/op1);
            } else {
                stk.push(stoi(str));
            }
        }
        return stk.top();
    }
};
int main(void) {
    Solution sl;
}
