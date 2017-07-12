/*
 * time : O(kn)
 * space : O(n)
 */

#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
class Solution {
public:
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    string getPermutation(int n, int k) {
          vector<int> nums;
        for(int i = 1; i <= n; i++)
            nums.push_back(i);
        
        k--;
        while(k--){
            int j = n-2;
            //step 1: find index j that nums[j] > nums[j+1]
            while(nums[j] > nums[j+1])
                j--;
            
            //step 2: find index i in [j+1, n] that nums[i] > nums[j] 
            //        and nums[i] is mininum, then swap nums[i] and nums[j]
            int min_val = 999999;
            int min_i = j;
            for(int i = j+1; i < n; i++){
                if(nums[i] > nums[j] && nums[i] < min_val){
                    min_val = nums[i];
                    min_i = i;
                }
            }
            swap(nums[j], nums[min_i]);
            
            //step 3: reverse nums[j+1, n]
            reverse(nums.begin()+j+1, nums.end());    
        }
        string res = "";
        for(int i = 0; i < n; i++)
            res += to_string(nums[i]);
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.getPermutation(3, 5) << endl;
    return 0;
}
