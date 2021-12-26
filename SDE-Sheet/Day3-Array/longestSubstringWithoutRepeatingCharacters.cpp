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
                map[s[right]] = right;
            }
            right++;
            maxi = max(maxi,length);
        }
        return maxi;
    }
};
