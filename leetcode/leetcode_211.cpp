class TrieNode{
  public:
    TrieNode(){
      for(int i = 0; i < 26; i++){
        child[i] = NULL;
      }
      isWord = false;
    }
  public:
    TrieNode* child[26];
    bool isWord;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word){
      TrieNode* curNode = root;
      for(auto ch : word){
        if(curNode->child[ch - 'a'] == NULL)
          curNode->child[ch - 'a'] = new TrieNode();
        curNode = curNode->child[ch - 'a'];
      }
      curNode ->isWord = true;
    }
    
    bool dfsSearch(string word, int index, TrieNode* curNode){
      if(curNode == NULL) return false;
      if(index == word.length()) return curNode->isWord;
      if(word[index] == '.'){
        for(int i = 0; i < 26; i++){
          if(dfsSearch(word, index+1, curNode->child[i]))
            return true;
        }
        return false;
      }
      return dfsSearch(word, index+1, curNode->child[word[index]-'a']);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfsSearch(word, 0, root);    
    }
public:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
