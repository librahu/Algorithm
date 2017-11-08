 class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		
		//����ԭ������ÿ��Ԫ�������ұߵ�һ���������Ԫ��֮���ӳ�� 
        unordered_map<int, int> m;
        //����ջ���Ӵ�С 
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
