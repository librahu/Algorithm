/**
 * "   123" -> 123 
 * "+-2" -> 0
 * "12a3" -> 12
 * overflow
 */
class Solution {
public:
    int myAtoi(string str) {
    	int i = 0;
    	while(i < str.size() && str[i] == ' ')
    		i++;
		int sign = 1;
		if(i < str.size() && str[i] == '-'){
			i++;
			sign = -1;
		}
		else if(i < str.size() && str[i] == '+')
			i++;
		long long ans = 0;
		for(; i < str.size(); i++){
			if(str[i] < '0' || str[i] > '9')
				break;
			ans = ans * 10 + (str[i] - '0');
			if(sign * ans > INT_MAX)
            	return INT_MAX;
        	if(sign * ans < INT_MIN)
            	return INT_MIN;
		}
		return sign * ans;
    }
};
