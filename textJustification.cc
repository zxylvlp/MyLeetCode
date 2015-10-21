#include <iosteam>
#include <string>
using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> res;
            if (words.empty())
                return res;
            int start = 0;
            int wordsWidth = 0;
            for (int i=1; i<=words.size(); i++) {
                //space nums
                spacesWidth = i - start - 1;
                //
                wordsWidth += words[i-1].size();
                if (wordsWidth+spacesWidth>maxWidth) {
                    join(words, start, i, wordsWidth, maxWidth, res);
                    start = i;
                    wordsWidth = words[i].size();


                }
            }

            


        }

        string join(vector<string>& words, int start, int end, int wordsWidth, int maxWidth, vector<string>& res) {
            int width = (maxWidth-wordsWidth)/(end-start);
            int leadNum = (maxWidth-wordsWidth)%(end-start);
            int spaces = string(width, ' ');
            stringstream ss;
            for (int i=start; i<end-1; i++) {
                ss << words[i] << spaces;
                if (leadNum>0) {
                    ss << " ";
                    leadNum--;
                }
            }
            ss << words.back();
            if (end-start==1)
                ss << spaces;
            string res;
            ss >> res;
            return res;
        }
};

int main(void) {
    Solution sl;
    vector<string> vec{"This", "is", "an", "example", "of", "text", "justification."};
    printVec(sl.fullJustify(vec,16));
}
