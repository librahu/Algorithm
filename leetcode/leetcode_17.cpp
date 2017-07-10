/*
 * Solution: brute force / dfs
 * time : approximately O(3^n)
 * space : approximately O(3^n)
 */

class Solution{
public:
    string button[10] = {" ", "*", "abc", "def", "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"};
    void helper(vector<string>& res, string digits, string cur, int pos){
        if(pos == digits.size()){
            res.push_back(cur);
            return;
        }
        
        int index = digits[pos] - '0';
        for(char ch : button[index]){
            helper(res, digits, cur+ch, pos+1);
        }
    }
    vector<string> letterCombinations(string digits){
        vector<string> res;
        if(digits == "")
            return res;
        helper(res, digits, "", 0);
        return res;
    }
};
