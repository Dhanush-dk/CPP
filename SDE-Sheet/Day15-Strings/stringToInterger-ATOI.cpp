class Solution {
public:
    int myAtoi(string s) {
        
        long ans = 0;
        int size = s.size();
        int index = 0;
        
        while(s[index] == ' ') index++;
        
        bool isNeg = s[index] == '-';
        if(s[index] == '-' || s[index] == '+') index++;
        
        while(index < size && ans < INT_MAX){
            if(s[index] >= '0' && s[index] <= '9')
                ans = ans*10 + (s[index]-'0');
            else break;
            index++;
        }
        
        ans = isNeg ? -ans : ans;
        
        return ans > INT_MAX ? INT_MAX : (ans < INT_MIN ? INT_MIN : ans);
    }
};
