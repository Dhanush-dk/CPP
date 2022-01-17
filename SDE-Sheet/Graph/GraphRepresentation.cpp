// Graph Representation using Adjacency Matrix
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e;
    int adj[n+1][n+1];
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}

// Graph Representation using Adj List
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e;
    vector<int> adj(n+1);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
