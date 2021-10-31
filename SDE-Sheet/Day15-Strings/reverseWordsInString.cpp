
//Leetcode

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string ans = "";
        int n = s.size();
        while(i < n){
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            int j = i + 1;
            while(j < n && s[j] != ' ') j++;
            string substring = s.substr(i, j-i);
            if(ans.size() == 0) ans += substring;
            else ans = substring + ' ' + ans;
            i = j+1;
        }
        return ans;
    }
};