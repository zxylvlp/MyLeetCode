#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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

        for (int i=0; i<numCourses; i++) {
            int j=0;
            for (; j<numCourses && d[j]!=0; j++);
            if (j==numCourses)
                return false;
            d[j] = -1;
            for (auto it=matrix[j].begin(); it!=matrix[j].end(); it++) {
                d[*it]--;
            }
        }
        return true;
    }
};

int main(void) {
    Solution sl;
}
