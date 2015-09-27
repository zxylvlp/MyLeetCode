#include <iostream>
using namespace std;
class Solution {

	public:
		string multiply (string num1, string num2) {
			int n1 = num1.length();
			int n2 = num2.length();
			string sum = string(n1+n2, '0');
			int carry = 0;
			int mul;
			for (int i=n1-1; i>=0; i--) {
				for (int j=n2-1; j>=0; j--) {
					mul = (sum[i+j+1] - '0') + (num1[i]-'0') * (num2[j]-'0') + carry;
					sum[i+j+1] = mul%10 + '0';
					carry = mul/10;
				}
				sum[i] += carry;
				carry = 0;
			}
			
			size_t startpos = sum.find_first_not_of("0");
			if (string::npos != startpos)
				return sum.substr(startpos);
			return "0";
		}
};

int main() {
	Solution sl;
	cout << sl.multiply("123", "321") << endl;
}

