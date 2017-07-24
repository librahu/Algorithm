/**
 * Solution : for each element, expand
 * time : O(n^2) suspicious
 * space : O(1)
 */
class Solution {
public:
    string longestPalindrome(string s) {
    	string res = "";
    	int maxlen = -1;
    	int left, right;
    	int n = s.size();
        for(int i = 0; i < n;){
			left = i;
			right = i;
			//skip the same elment
			while(right < n-1 && s[right] == s[right+1])
				right ++;
				
			i = right + 1;
			//expand
			while(left > 0 && right < n-1 && s[left-1] == s[right+1]){
				left --;
				right ++;
			}
			if(right - left + 1 > maxlen){
				maxlen = right - left + 1;
				res = s.substr(left, maxlen);
			}
		}
        return res;
    }
};
