#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
            unordered_set<string> head, tail, *phead, *ptail;
            head.insert(beginWord);
            tail.insert(endWord);
            int dist = 2;
            while (!head.empty() && !tail.empty()) {
                if (head.size() < tail.size()) {
                    phead = &head;
                    ptail = &tail;
                } else {
                    phead = &tail;
                    ptail = &head;
                }
                unordered_set<string> tmp;
                for (auto itr=phead->begin(); itr!=phead->end(); itr++) {
                    string word = *itr;
                    for (int i=0; i<(int)word.length(); i++) {
                        char letter = word[i];
                        for (int j=0; j<26; j++) {
                            word[i] = 'a' + j;
                            if (ptail->find(word)!=ptail->end())
                                return dist;
                            if (wordList.find(word)!=wordList.end()) {
                                tmp.insert(word);
                                wordList.erase(word);
                            }
                        }
                        word[i] = letter;
                    }
                }
                dist++;
                swap(*phead, tmp);

            }
            return 0;
            
        }
};
int main(void) {
    Solution sl;
}
