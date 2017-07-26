/**
 * Solution : dp
 * 1. s[i] == p[j] : dp[i][j] = dp[i-1][j-1];
 * 2. p[j] == '.' : dp[i][j] = dp[i-1][j-1];
 * 3. p[j] == '*': 
 *    1) p[j-1] != s[i] : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
 *    2) p[j-1] == s[i]  or p[j-1] == '.'
 *                            dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
 *                          or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
 *                         or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
 * space : O(n^2)
 * time : O(n^2)
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.length()+1, vector<bool>(p.length()+1, false)); 
        dp[0][0] = true;
        for(int j = 0; j < p.size(); j++){
        	if(p[j]=='*' && dp[0][j-1])
        		dp[0][j+1] = true;
		}
        
        for(int i = 0; i < s.size(); i++){
        	for(int j = 0; j < p.size(); j++){
				if(s[i] == p[j] || p[j] == '.')
        			dp[i+1][j+1] = dp[i][j];
        		if(p[j] == '*'){
        			if(s[i] != p[j-1] && p[j-1] != '.')
        				dp[i+1][j+1] = dp[i+1][j-1];
        			else
        				dp[i+1][j+1] = (dp[i+1][j-1] || dp[i+1][j] || dp[i][j+1]);
				}
			}
		}
		return dp[s.length()][p.length()];
    }
};
