/**
 * Solution : DP + scrolling array 
 * dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 * time : O(n)
 * space : O(1)
 */ 
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(3, 0);
        for(int i = 1; i <= nums.size(); i++){
            dp[(i+1)%3] = max(dp[(i-1)%3] + nums[i-1], dp[i%3]);
        }
        return dp[(nums.size()+1)%3];
    }
};
