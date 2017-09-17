/** 
 * Solution : simulation
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int r = 0;
        int c = -1;
        int i =  1;
        while(i <= n * n){
        	//turn right
            c++;
        	while(c < n && matrix[r][c] == 0){
        		matrix[r][c] = i++;
        		c++;
        	}
        	c--;
        
        	//turn down
        	r++;
            while(r < n && matrix[r][c] == 0){
        		matrix[r][c] = i++;
        		r++;
        	}
        	r--;
            
        	//turn left
            c--;
        	while(c >= 0 && matrix[r][c] == 0){
                matrix[r][c] = i++;
        		c--;
        	}
        	c++;
            
        	//turn up
        	r--;
            while(r >= 0 && matrix[r][c] == 0){
        		matrix[r][c] = i++;
        		r--;
        	}
        	r++;
        }
        return matrix;
    }
};