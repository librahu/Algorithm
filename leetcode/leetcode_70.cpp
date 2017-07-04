#include<iostream>
#include<vector>
using namespace std;

/**
 * DP : f(n) = f(n-1) + f(n-2); f(1) = f(0) = 1
 * time : O(n)
 * space : O(1)
 */
int climbStairs(int n){
  vector<int> ctn(3,0);
  ctn[0] = 1;
  ctn[1] = 1;
  for(int i = 2; i < n; i++){
    ctn[i%3] = ctn[(i-1)%3] + ctn[(i-2)%3];
  }
  return ctn[n%3];
}

int main()
{
  for(int i = 1; i <= 10; i++)
    cout << climbStairs(i) << endl;
  return 0;
}
