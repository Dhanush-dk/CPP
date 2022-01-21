#include <bits/stdc++.h>
using namespace std;
void findPath(vector<int> adj[], int n, int e,int s){
    
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        
        for(auto i : adj[node]){
            if(dist[node] + 1 < dist[i]){
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
    
    for(auto i : dist){
        cout << i << " ";
    }
}
int main()
{
    int n, e;
    cout << "Enter no of nodes and edges:\n";
    cin >> n >> e;
    vector<int> adj[n];
    cout << "Enter the input:\n";
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cout << "Enter source:";
    cin >> s;
    findPath(adj, n, e, s);

    return 0;
}

✔✔  SAMPLE INPUT:
Enter no of nodes and edges:
9
11
Enter the input:
0 1
0 3
1 3
1 2
2 6
3 4
4 5
5 6
6 7
6 8
7 8
Enter source:5
  
✔✔  SAMPLE OUTPUT:
3 3 2 2 1 0 1 2 2 
  
✌✨🤞
