#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int strStr(string haystack, string needle) {

			const int size_h = haystack.size();
			const int size_n = needle.size();

			if (size_n==0) return 0;
			vector<int> next(size_n, 0);
			for (int i=1; i<size_n; i++) {
				int pos = next[i-1];
				while(pos>0 && needle[i]!=needle[pos])
					pos = next[pos-1];
				if (needle[i]==needle[pos])
					next[i] = pos + 1;
			}

			int idx_n=0, idx_h=0;
			for (;idx_h<size_h;idx_h++) {
				while (idx_n>0 && needle[idx_n]!=haystack[idx_h])
					idx_n=next[idx_n-1];
				if (needle[idx_n]==haystack[idx_h])
					idx_n++;
				if (idx_n==size_n) return idx_h-size_n+1;
			}
			return -1;

		}

};
int main() {
	Solution sl;
	int result = sl.strStr("asdffdsa", "dffd");
	cout << result << endl;
}
