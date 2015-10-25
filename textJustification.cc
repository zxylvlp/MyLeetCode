#include <iostream>
#include <string>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> res;
            int begin = 0;
            while (begin < words.size()) {
                int last = begin;
                int lineSize = words[begin].size();
                begin++;
                while (begin<words.size() && lineSize+1+words[begin].size()<=maxWidth) {
                    lineSize += 1 + words[begin].size();
                    begin++;
                }
                int spaces = 1, extra = 0;
                if (begin<words.size() && begin!=last+1) {
                    spaces = (maxWidth - lineSize) / (begin - last -1)+1;
                    extra = (maxWidth - lineSize) % (begin - last - 1);
                }

                res.push_back(words[last]);
                last++;
                while (extra) {
                    res.back().append(spaces+1, ' ');
                    res.back().append(words[last]);
                    last++;
                    extra--;
                }
                while (last<begin) {
                    res.back().append(spaces, ' ');
                    res.back().append(words[last]);
                    last++;
                }
                res.back().append(maxWidth-res.back().size(), ' ');
            }
            return res;
        }

};

int main(void) {
    Solution sl;
    vector<string> vec{"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res = sl.fullJustify(vec,16);
    printVec(res);
}
