Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        bool flag = 1;
        for(int i = 1; i <= size/2; i++){
            if(size % i == 0){
                flag = 1;
                string a = s.substr(0, i);
                int sz = a.size();
                int j = i;
                while(j < size){
                    if(a != s.substr(j, sz)){
                        flag = 0;
                        break;
                    }
                    j += sz;
                }
                if(flag == 1) return true;
            }
        }
        return false;
    }
};
