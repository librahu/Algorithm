/**
 * solution dp
 * suppose s[m...i-1] is current longest substring
 * if s[i] not in s[m...i-1] then longest = i-m+1
 * else m = max(m, hash[s[i]] + 1) logest = i-m+1
 * time o(n)
 * space o(1)
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int m = 0, longest = 0;
        for(int i = 0; i < s.size(); i++){
            m = m > hash[s[i]]+1 ? m : hash[s[i]]+1;
            hash[s[i]] = i;
            longest = longest > i-m+1 ? longest : i-m+1;
        }
        return longest;
    }
};


