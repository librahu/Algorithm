/**
  * recursively
  * b[1~pos] = 10 * b[1~pos-1] + b[pos]
  * a^(b[1~pos]) % 1337 = a^(10*b[1~pos-1]+b[pos])%1337 = ((a^(b[1~pos-1]))^10)%1337 * ((a^b[pos])%1337) % 1337
  * time : O(n)
  * space : O(n)
  */
class Solution{
public:
  int superPow(int a, vector<int>& b){
    if(b.size() == 0)
      return 1;
    return helper(a, b, b.size()-1);
  }

  int helper(int a, vector<int>& b, int pos){
    if(pos < 0)
      return 1;
    return mod(helper(a, b, pos-1), 10) * mod(a, b[pos]) % 1337;
  }

  int mod(int a, int power){
    if(power == 0)
      return 1;
    return mod(a, power-1) * (a % 1337) % 1337;
  }
};
