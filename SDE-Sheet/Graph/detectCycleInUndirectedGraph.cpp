// CYCLE DETECTION IN UNDIRECTED GRAPH USING BREADTH FIRST SEARCH
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int node, vector<int>&vis, vector<int> adj[]){
        queue<pair<int, int>> q;
        q.push({node,-1});
        vis[node] = 1;
        while(!q.empty()){
            int cur = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto i : adj[cur]){
                if(vis[i] == 1 && parent != i) 
                    return true;
                if(!vis[i]){
                    q.push({i, cur});
                    vis[i] = 1;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(checkCycle(i, vis, adj)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
