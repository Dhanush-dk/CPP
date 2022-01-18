// Leetcode easy
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size() + 2;
        vector<int> adj[n];
        int ans;
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(adj[u].size() == edges.size()) return u;
            if(adj[v].size() == edges.size()) return v;
        }
        
        return -1;
    }
};
