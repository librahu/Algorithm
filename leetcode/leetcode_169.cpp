class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ctn = 1;
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != res)
                ctn --;
            else
                ctn ++;
            if(ctn == 0){
                ctn ++;
                res = nums[i];
            }
        }
        return res;
    }
};
