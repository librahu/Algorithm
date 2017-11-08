class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = nums[0];
        for(auto num : nums)
            minNum = min(minNum, num);
        
        int res = 0;
        for(auto num : nums)
            res += (num - minNum);
        
        return res;
    }
};
