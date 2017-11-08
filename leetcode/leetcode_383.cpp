class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        
        for(auto ch : magazine)
            m[ch] ++;
        
        for(auto ch : ransomNote){
            if(m[ch] > 0)
                m[ch] --;
            else
                return false;
        }
        return true;
    }
};
