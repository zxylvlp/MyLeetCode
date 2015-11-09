#include "Point.hh"
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int generateGCD(int a, int b) {
            if (b==0)
                return a;
            return generateGCD(b, a%b);
        }
        int maxPoints(vector<Point> &points) {
            if (points.size()<=2)
                return points.size();
            unordered_map<int, unordered_map<int, int>> m;
            int result = 0;
            for (unsigned int i=0; i<points.size(); i++) {
                m.clear();
                int overlap=0, localmax=0;
                for (unsigned int j=i+1;j<points.size(); j++) {
                    int x = points[j].x - points[i].x;
                    int y = points[j].y - points[i].y;
                    if (x==0&&y==0) {
                        overlap++;
                        continue;
                    }
                    int gcd = generateGCD(x, y);
                    if (gcd) {
                        x/=gcd;
                        y/=gcd;
                    }
                    int curr = ++m[x][y];
                    localmax = max(curr, localmax);
                }
                result = max(result, localmax+overlap+1);
            }
            return result;
        }
};
int main(void) {
    Solution sl;
}
