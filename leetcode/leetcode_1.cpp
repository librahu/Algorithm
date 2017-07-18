/**
 * solution : search in map
 * time O(n)
 * space O(n)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myMap;
        vector<int> res(2, 0);
        for(int i = 0; i < nums.size(); i++){
          if(myMap[target-nums[i]] == 0){
            myMap[nums[i]] = i + 1; //careful
          }
          else{
            res[0] = myMap[target-nums[i]] - 1; //careful
            res[1] =  i;
            return res;
          }
        }
    }
};
