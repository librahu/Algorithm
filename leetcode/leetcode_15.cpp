/**
 * time : O(n^2)
 * space : O(1)
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        
		sort(nums.begin(), nums.end());
        
        int left, right, target;
        int n = nums.size();
		for(int i = 0; i < n - 2; i++){
            
			left = i + 1;
			right = n - 1;
			target = -nums[i];
			while(left < right){
				if(nums[left] + nums[right] > target)
					right --;
				else if(nums[left] + nums[right] < target)
					left ++;
				else{
					res.push_back(vector<int>{-target, nums[left], nums[right]});
					
					while(left < right && nums[left] == nums[left+1]) left ++;
					while(left < right && nums[right] == nums[right-1]) right --;
                    
                    left ++;
                    right --;
				}
			}
			
			while(i+1 < n && nums[i] == nums[i+1]) i++;
		}
        
        return res;
    	
    }
};
