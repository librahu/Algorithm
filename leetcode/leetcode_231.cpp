class Solution {
public:
    bool isPowerOfTwo(int n) {
               
        //return n > 0 && !(n & (n-1));    //bit way 
        return n>0 && (1073741824 % n == 0); // math way 2^31 == 1073741824
    }
};
