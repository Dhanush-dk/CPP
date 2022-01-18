//Easy Leetcode Soln
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
		vector<int> adj[n];
		queue<int> q;
        vector<int> vis(n, 0);
		
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        q.push(source);
        vis[source] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination) return true;
            for(auto i : adj[node]){
                if(vis[i] != 1){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return false;
    }
};
