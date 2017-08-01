//easy 
class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.size() - needle.size();
        for(int i = 0; i <= size; i++){
            int j = 0;
            while(i+j < haystack.size() && j < needle.size() && haystack[i+j] == needle[j])
                j++;
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};
