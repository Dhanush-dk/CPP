//Leetcode soln

There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
  
A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
  
Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<vector<int>> isConnected){
        vis[node] = 1;
        vector<int> neighbours = isConnected[node];
        for(int i = 0; i < neighbours.size(); i++){
            if(i == 1 && vis[i] == 0){
                dfs(i, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size = isConnected.size();
        vector<int> vis(size, 0);
        int count = 0;
        for(int i = 0; i < size; i++){
            if(!vis[i]){
                dfs(i, vis, isConnected);
                count++;
            }
        }
        return count;
    }
};
