//’“πÊ¬… 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        
        int r = 0;
        int c = -1;
        
        m--;
        while(m>=0 || n>=0){
            //turn right
            for(int i = 0; i < n && m >= 0; i++){
                c++;
                res.push_back(matrix[r][c]);
            }
            n--; //**** 
            //turn down
            for(int i = 0; i < m && n >= 0; i++){
                r++;
                res.push_back(matrix[r][c]);
            }
            m--;  //****
            //turn left
            for(int i = 0; i < n && m >= 0; i++){
                c--;
                res.push_back(matrix[r][c]);
            }
            n--;  //****
            //turn up
            for(int i = 0; i < m && n >= 0; i++){
                r--;
                res.push_back(matrix[r][c]);
            }
            m--;  //****
        }
        return res;
    }
};
