/**
 * Solution Dp
 * time : O(n)
 * space : O(n)
 */ 
class Solution {
public:
    vector<int> countBits(int num) {
        int pow = 1;
        vector<int> res;
        res.push_back(0);
        for(int i = 1; i <= num; i++){
            
            //res.push_back(res[i-pow] + 1);
            //if(i == pow*2-1){
            //    pow <<= 1;
            //}
            res.push_back(res[i&(i-1)] + 1);
        }
        return res;
    }
};
