/** 
 * Solution : dp
 * time : O(n)
 * space : O(1)
 */
 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 1)
            return 0;
        
        int maxSub = nums[0]; //max subarray end with nums[i]
        int ans = maxSub;
        for(int i = 1; i < nums.size(); i++){
            maxSub = max(maxSub + nums[i], nums[i]);
            ans = max(ans, maxSub);
        }
        return ans;
    }
};
