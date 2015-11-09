#include <string>
using namespace std;
class TrieNode {
public:
    TrieNode *next[26];
    bool is_word;
    // Initialize your data structure here.
    TrieNode(bool b=false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *p = root;
        for (int i=0; i<s.size(); i++) {
            if (p->next[s[i]-'a']==nullptr)
                p->next[s[i]-'a'] = new TrieNode();
            p = p->next[s[i]-'a'];
        }
        p->is_word=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = find(word);
        return p && p->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return !find(prefix);
        
    }

private:
    TrieNode* root;
    TrieNode* find(string key) {
        TrieNode *p = root;
        for (int i=0; i<key.size() && p!=nullptr; i++) {
            p = p->next[key[i]-'a'];
        }
        return p;
    }
};

int main(void) {
// Your Trie object will be instantiated and called as such:
    Trie trie;
    trie.insert("key");
    trie.search("key");
}
