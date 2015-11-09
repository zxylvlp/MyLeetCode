#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> matrix(numCourses);
        for (int i=0; i<prerequisites.size(); i++) {
            matrix[prerequisites[i].second].insert(prerequisites[i].first);
        }
        vector<int> d(numCourses, 0);
        for (int i=0; i<numCourses; i++) {
            for (auto it=matrix[i].begin(); it!=matrix[i].end(); it++) {
                d[*it]++;
            }
        }

        vector<int> res;
        for (int i=0; i<numCourses; i++) {
            int j=0;
            for (; j<numCourses && d[j]!=0; j++);
            if (j==numCourses)
                return vector<int>();
            d[j] = -1;
            res.push_back(j);
            for (auto it=matrix[j].begin(); it!=matrix[j].end(); it++) {
                d[*it]--;
            }
        }
        return res;
    }
};

int main(void) {
    Solution sl;
}

