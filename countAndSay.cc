#include <iostream>
using namespace std;
class Solution {
	public:
		string countAndSay(int n) {
			string result = "1";
			if (n<1) return "";
			while (n>1) {
				auto iter=result.begin()+1, end=result.end();
				char c = result[0];
				int num = 1;
				stringstream nResult;
				while (iter<=end) {
					char cc = *iter;
					if(cc!=c) {
						nResult << char(num+'0') << c;
						num = 1;
						c = cc;
					} else {
						num++;
					}
					iter++;
				}

				result = nResult.str();
				n--;
			}
			return result;
		}

};

int main() {
	Solution sl;
	cout << sl.countAndSay(4) << endl;
}
