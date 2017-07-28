/**
 * Solution : DP
 * time : O(n)
 * space : O(n)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
		vector<int> max_dp(nums.size(), 0);
		vector<int> min_dp(nums.size(), 0);
		
		max_dp[0] = nums[0];
		min_dp[0] = nums[0];
		int ans = nums[0];
		for(int i = 1; i < nums.size(); i++){
			max_dp[i] = max(max(nums[i], max_dp[i-1] * nums[i]), min_dp[i-1] * nums[i]);
			min_dp[i] = min(min(nums[i], min_dp[i-1] * nums[i]), max_dp[i-1] * nums[i]);
			ans = max(ans, max_dp[i]);
		}        
		return ans;
    }
};

/**
 * time : O(n)
 * space : O(1)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {		
		int max_dp = nums[0];
		int min_dp = nums[0];
		int ans = nums[0];
		int tmp;
		for(int i = 1; i < nums.size(); i++){
			tmp = max_dp;
			max_dp = max(max(nums[i], max_dp * nums[i]), min_dp * nums[i]);
			min_dp = min(min(nums[i], min_dp * nums[i]), tmp * nums[i]);
			ans = max(ans, max_dp);
		}        
		return ans;
    }
};

