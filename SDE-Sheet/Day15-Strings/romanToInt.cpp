class Solution {
public:
    int getNum(char c){
        switch(c){
            case 'M': 
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        int i = 0;
        while(i < s.size()){
            int n = getNum(s[i]);
            int m = getNum(s[i+1]);
            if(n < m){
                ans += m - n;
                i += 2;
            }
            else{
                ans += getNum(s[i]);
                i++;
            }
        }
        return ans;
    }
};
