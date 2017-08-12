/**
 * easy
 * brute force
 */ 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        
        for(int k = 1; k <= n/2; k++){
            if(n % k)
                continue;
            string ss = s.substr(0, k);
            int p = k;
            for(int i = 1; i < n/k; i++){
                string st = s.substr(p, k);
                if(st != ss)
                    break;
                p += k;
            }
            if(p == n)
                return true;
        }
        return false;
    }
};
