class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string s = strs[i];
            int j = 0;
            for(; j < strs[i].size(); j++){
                if(res[j] != s[j]) break;
            }
            res = res.substr(0, j);
        }
        return res;
    }
};
