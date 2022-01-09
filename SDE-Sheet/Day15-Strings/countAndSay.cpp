// Input: n = 4
// Output: "1211"
// Explanation:
// countAndSay(1) = "1"
// countAndSay(2) = say "1" = one 1 = "11"
// countAndSay(3) = say "11" = two 1's = "21"
// countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

class Solution {
public:
    string say(string s){
        if(s.empty()) return "1";
        int i = 0;
        string t = "";
        while(i < s.size()){
            char c = s[i];
            int j = i+1;
            int count = 1;
            while(j < s.size() && c == s[j] ){
                count++;
                j++;
            }
            string cnt = to_string(count);
            t += cnt + c;
            i = j;
        }
        return t;
    }
    string countAndSay(int n) {
        string s = "";
        for(int i = 1; i <= n; i++){
            s = say(s);
        }
        return s;
    }
};
