/**
  * Binary Search
  */ 
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num / 2 + 1;

        while(left <= right){
            long long mid = (left + right) / 2;
            if(mid * mid == num) return true;
            else if(mid * mid > num)
                right = (int)mid - 1;
            else
                left = (int)mid + 1;
        }
        return false;
    }
};
