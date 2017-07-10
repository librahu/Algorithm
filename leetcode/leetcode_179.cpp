/**
 * Solution : sort
 * time : O(nlogn)
 * space : O(n)
 */ 
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_str;
        for(int num : nums){
            nums_str.push_back(to_string(num));
        }
        sort(nums_str.begin(), nums_str.end(), [](string s1, string s2){
            return s1 + s2 > s2 + s1;
        });
        string res = "";
        for(string num : nums_str){
            res += num;
        }
        if(res[0] == '0') return "0";
        return res;
    }
};
