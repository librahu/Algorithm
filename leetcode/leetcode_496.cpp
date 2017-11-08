 class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		
		//建立原数组中每个元素与其右边第一个比他大的元素之间的映射 
        unordered_map<int, int> m;
        //单调栈，从大到小 
        stack<int> s;
        for(auto num : nums){
            while(!s.empty() && num > s.top()){
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        vector<int> res;
        for(auto num : findNums)
            res.push_back(m.count(num) ? m[num] : -1);
        
        return res;
    }
};
