//GFG
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        for(int i = n-1; i >=0; i--){
            s.push(i);
        }
        while(s.size() > 1){
            int i = s.top();
            s.pop();
            int j = s.top();
            s.pop();
            if(M[i][j] == 1) s.push(j);
            else s.push(i);
        }
        //if(s.empty()) return -1;
        int x = s.top();
        s.pop();
        for(int i = 0; i < n; i++){
            if(i != x && (M[x][i] == 1 || M[i][x] == 0)) return -1;
        }
        return x;
    }
};