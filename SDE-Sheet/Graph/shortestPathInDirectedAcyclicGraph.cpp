#include <bits/stdc++.h>
using namespace std;
void findTopo(int node, vector<pair<int,int>> adj[], int vis[], stack<int>&s){
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i.first]){
            findTopo(i.first, adj, vis, s);
        }
    }
    s.push(node);
}
void findShortestPath(vector<pair<int,int>> adj[], int n,int source){
    
    stack<int>s;
    int vis[n] = {0};
    
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            findTopo(i, adj, vis, s);
        }
    }
    
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    
    while(!s.empty()){
        
        int node = s.top();
        s.pop();
        
        if(dist[node] != INT_MAX){
            for(auto i : adj[node]){
                if(dist[node] + i.second < dist[i.first]){
                    dist[i.first] = dist[node] + i.second;
                }
            }
        }
    }
    
    for(auto i : dist){
        i == INT_MAX ? cout<< "Infinity " : cout << i << " "; 
    }
}
int main()
{
    int n, e;
    cout << "Enter no of nodes and edges:\n";
    cin >> n >> e;
    vector<pair<int,int>> adj[n];
    cout << "Enter the node, adj node and edge weight(distance):\n";
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    int s;
    cout << "Enter source:";
    cin >> s;
    findShortestPath(adj, n, s);

    return 0;
}

SAMPLE INPUT:
Enter no of nodes and edges:
6
7
Enter the node, adj node and edge weight(distance):
0 1 2
0 4 1 
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1
Enter source:0

SAMPLE OUTPUT:  
0 2 3 6 1 5 
