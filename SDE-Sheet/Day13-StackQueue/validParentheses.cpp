class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto i : s){
            if(i == '(' || i == '[' || i == '{')
                stk.push(i);
            else{
                if(stk.size() == 0) return false;
                char c = stk.top();
                stk.pop();
                if((c == '(' && i == ')') || (c == '[' && i == ']') || (c == '{' && i == '}'))
                    continue;
                else return false;
            }
        }
        return stk.empty();
    }
};