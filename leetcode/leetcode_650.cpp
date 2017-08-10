/**
 * Solution dp
 * time : O(n)
 * space : O(n)
 */ 
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(1100, 0);
        return helper(dp, n);
    }
    int helper(vector<int>& dp, int n){
        if(n == 1)
            return 0;
        if(dp[n])
            return dp[n];
        
        for(int i = 2; i <= n; i++){
            if(n%i == 0){
                dp[n] = helper(dp, n / i) + i;

                return dp[n];
            }
        }
    }
};
