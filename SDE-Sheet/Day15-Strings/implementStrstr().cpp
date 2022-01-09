//Solution 1
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        for(int i = 0; i < haystack.size(); i++){
            int j = 0;
            for(;j < needle.size(); j++){
                if(i + j == haystack.size()) return -1;
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == needle.size()) return i;
        }
        return -1;
    }
};

//Solution 2
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() < needle.size()) return -1;  
        int n = needle.size();
        for(int i = 0; i <= haystack.size()-n; i++)
        {  
            if(haystack[i] == needle[0]){
                if(haystack.substr(i,n) == needle)
                    return i;
            }   
        }
        return -1;
    }
};
