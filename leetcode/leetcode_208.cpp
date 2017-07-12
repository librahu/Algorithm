class TrieNode{
public:
    bool isWords;
    TrieNode* next[26];
    
    TrieNode(){
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
        isWords =false;
    }
};
class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(char ch : word){
            int index = ch - 'a';
            if(!cur->next[index])
                cur->next[index] = new TrieNode();
            cur = cur->next[index];
        }
        cur->isWords = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(char ch : word){
            int index = ch - 'a';
            if(!cur->next[index])
                return false;
            cur = cur->next[index];
        }
        return cur->isWords;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char ch : prefix){
            int index = ch - 'a';
            if(!cur->next[index])
                return false;
            cur = cur->next[index];
        }
        return true;
    }
};
