/**
 * time :O()
 * space : O()
 *
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		if(n == 0)	return res;

		helper(res, "", 0, 0, n);
		return res;
    }
    
    void helper(vector<string>& res, string str, int left, int right, int n){
    	if(left + right == 2 * n){
    		res.push_back(str);
    		return ;
		}
		/********************/
		if(left < n)
			helper(res, str+'(', left+1, right, n);
		/********************/
		if(right < left)
			helper(res, str+')', left, right+1, n);
	}
};

