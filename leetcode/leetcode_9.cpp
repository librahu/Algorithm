class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)	return false;
		int r_x = 0;
        int xx = x;
        while(xx){
        	r_x = 10 * r_x + xx % 10;
        	xx /= 10; 
		}
		return x == r_x;
    }
};
