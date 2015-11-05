#include "UndirectedGraphNode.hh"
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return node;
        if (map.count(node)==0) {
            map[node] = new UndirectedGraphNode(node->label);
            for (auto s:node->neighbors)
                map[node]->neighbors.push_back((cloneGraph(s)));
        }
        return map[node];
    }
};
int main(void) {
    Solution sl;
}
