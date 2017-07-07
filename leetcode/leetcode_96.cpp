/**
 * dp : f(i) = f(j) * f(i-1-j) when 0 < j < i;
 * time : O(n^2)
 * space : O(n) 
 */
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++){
        	dp[i] = 0;
        	for(int j = 0; j < i; j++){
        		dp[i] += dp[j] * dp[i-1-j];
			}
		}
		return dp[n];
    }
};
