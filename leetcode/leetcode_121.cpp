/**
 * dp
 * time : O(n)
 * space : O(1)
 */ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            min_price = min(min_price, prices[i]);
            ans = max(prices[i] - min_price, ans);
        }
        return ans;
    }
};
