class Solution {
public:
    int distributeCandies(vector<int>& candies) {
		set<int> candies_set;
		for(int i = 0; i < candies.size(); i++){
			candies_set.insert(candies[i]);
		}        
		return min(candies_set.size(), candies.size() / 2);
    }
};
