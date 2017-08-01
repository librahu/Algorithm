//easy 
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)  return "1";
        
        string preStr = "1";
        int ctn;
        string str;
        for(int i = 2; i <= n; i++){
            str = "";
            for(int j = 0; j < preStr.size(); j++){
                ctn = 1;
                while(j+1 < preStr.size() && preStr[j] == preStr[j+1]){
                    j++;
                    ctn ++;
                }
                str = str + to_string(ctn) + preStr[j];
            }
            preStr = str;
        }
        return str;
    }
};
