/**
 * solution : simulation
 * time : O(n)
 * space : O(n)
 */
class Solution {
public:
    string convert(string s, int numRows) {
    	if(numRows <= 1)	return s;   	
  		vector<string> res(numRows, "");
  		int ctn = 0;
		for(int i = 0; i < s.size();){
			while(i < s.size() && ctn < numRows){
				res[ctn]+=s[i];
				ctn ++;
				i++;
			}
			ctn -= 2;
			while(i < s.size() && ctn >= 0){
				res[ctn]+=s[i];
				ctn --;
				i++;
			}
			ctn += 2;
		}
		string ans = "";
		for(int i = 0; i < numRows; i++){
				ans += res[i];
		}
		return ans;
    }
};
