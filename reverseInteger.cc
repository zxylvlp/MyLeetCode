#include <iostream>
#include <limits.h>
using namespace std;
class Solution {

	public:
		int reverse(int n) {
			long long sum = 0;
			int r;
			while(n!=0) {
				r = n%10;
				n = n/10;
				sum = r + sum*10;
				if (sum > INT_MAX || sum < INT_MIN) 
					return 0;
			}
			return sum;
		}
};
int main() {
	Solution solution;
	int n = -123;
	cout<<INT_MAX<<endl;
	cout<<solution.reverse(n)<<endl;
}

