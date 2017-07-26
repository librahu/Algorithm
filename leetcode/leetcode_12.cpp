class Solution {
public:
    string intToRoman(int num) {
    	//1,2,3,4,5,6,7,8,9
        vector<string> roman_1= {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 
		//10,20,30,40,50,60,70,80,90
		vector<string> roman_2 = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		//100,200,300,400,500,600,700,800,900
		vector<string> roman_3 = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		//1000,2000,3000
		vector<string> roman_4 = {"M", "MM", "MMM"};
		
		string res = "";
		
		if(num / 1000){
			res += roman_4[num / 1000 - 1];
			num = num % 1000;
		}
		
		if(num / 100){
			res += roman_3[num / 100 - 1];
			num = num % 100;
		}
		
		if(num / 10){
			res += roman_2[num / 10 - 1];
			num = num % 10;
        }
        
        if(num)
		    res += roman_1[num - 1];
		
		return res;
    }
};
