#include <iostream>
#include <limits.h>
using namespace std;
typedef long long ll;
class Solution {
	public:
		int divide(int dividend, int divisor) {
			ll ans = 0;
			ll n = abs(ll(dividend));
			ll d = abs(ll(divisor));
			while(n>=d) {
				ll a = d;
				ll m = 1;
				while(a<<1 < n) {
					a = a<<1;
					m = m<<1;
				}
				ans += m;
				n = n - a;
			}
			if ((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) {
				ans = -ans;
				if (ans<INT_MIN) 
					ans = INT_MIN;
			} else {
				if (ans>INT_MAX)
					ans = INT_MAX;
				
			}
			return ans;
		}

};
int main() {
	Solution sl;
	int result = sl.divide(100, 3);
	cout << result << endl;
}
