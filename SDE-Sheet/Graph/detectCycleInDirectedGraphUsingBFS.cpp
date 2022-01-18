// Cycle detection using Topological Sort

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
      vector<int> ans;
	    vector<int> indegree(V, 0);
	    
	    for(int i = 0; i < V; i++){
	        for(auto j : adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    int count = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        count++;
	        ans.push_back(node);
	        for(auto i : adj[node]){
	            indegree[i] -= 1;
	            if(indegree[i] == 0){
	                q.push(i);
	            }
	        }
	    }
	    if(V == count) return false;
        return true;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
