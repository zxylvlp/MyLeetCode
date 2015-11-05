#include "UndirectedGraphNode.hh"
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    queue<UndirectedGraphNode*> que;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return node;
        map[node] = new UndirectedGraphNode(node->label);
        que.push(node);
        while(!que.empty()) {
            UndirectedGraphNode *p = que.front();
            que.pop();
            for (auto s: p->neighbors) {
                if (map.find(s)==map.end()) {
                    map[s] = new UndirectedGraphNode(s->label);
                    que.push(s);
                }
                map[p]->neighbors.push_back(map[s]);
            }
        }
        return map[node];
    }
};
int main(void) {
    Solution sl;
}
