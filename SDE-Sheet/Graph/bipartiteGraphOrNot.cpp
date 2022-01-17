// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool check(int node, vector<int>&col, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        col[node] = 0;
        while(!q.empty()){
            int index = q.front();
            q.pop();
            for(auto i : adj[index]){
                if(col[i] == col[index]) return false;
                if(col[i] == -1){
                    col[i] = 1 - col[index];
                    q.push(i);
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V, -1);
	    
	    for(int i = 0; i < V; i++){
	        if(col[i] == -1){
	            if(!check(i, col, adj)) return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
