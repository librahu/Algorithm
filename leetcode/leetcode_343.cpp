/**
 * Solution DP
 * time : O(n^2)
 * space : O(n)
 */
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp = vector<int>(n+1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i-1; j++){
                dp[i] = max(dp[i], max(j, dp[j]) * max(i-j, dp[i-j]));
            }
        }
        return dp[n];
    }
};
/**
 * Solution : math
 * reference : https://discuss.leetcode.com/topic/45341/a-simple-explanation-of-the-math-part-and-a-o-n-solution/2
 * time O(n)
 * space : O(1)
 */
class Solution {
public: 
	int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int product = 1;
        while(n>4){
            product*=3;
            n-=3;
        }
        product*=n;
        
        return product;
    }
}
