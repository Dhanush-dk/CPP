Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0

class Solution {
public:
    int lengthOfLongestSubstring(string s) {  
        int left = 0;
        int right = 0;
        int length = 0;
        int maxi = -1;
        unordered_map<char,int> map;
        if(s.empty()) return 0;
        while(right < s.size()){
            if(map.find(s[right]) != map.end()){
                if(map[s[right]] >= left){
                    left = map[s[right]] + 1;
                    map[s[right]] = right;
                    length = right - left + 1;
                }
                else{
                    length++;
                    map[s[right]] = right;
                }
            }
            else{
                length++;
                map.insert({s[right],right});
            }
            right++;
            maxi = max(maxi,length);
        }
        return maxi;
    }
};