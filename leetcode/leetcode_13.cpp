class Solution {
public:
    int romanToInt(string s) {
        map<char, int> hash;
        //I(1)£¬V(5)£¬X(10)£¬L(50)£¬C(100)£¬D(500)£¬M(1000)
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        int res = 0;
        for(int i = 0; i < s.size(); ){
            if(i+1 < s.size() && hash[s[i+1]] > hash[s[i]]){
                res += (hash[s[i+1]] - hash[s[i]]);
                i += 2;
            }
            else{
                res += hash[s[i]];
                i++;
            }
        }
        return res;
    }
};
