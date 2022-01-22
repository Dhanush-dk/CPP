// Leetcode qn no. 684
// This problem is solved by using Union and Find Algorithm

class Solution {
public:
    int find(int x, vector<int>parent){
        return parent[x] == x ? x : find(parent[x], parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> ans(2, 0);
        vector<int> parent(size+1, 0);
        for(int i = 0; i <= size; i++)
            parent[i] = i;
        for(int i = 0; i < size; i++){
            int x = find(edges[i][0], parent);
            int y = find(edges[i][1], parent);
            if(x != y){
                parent[y] = x;
            }
            else{
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
            }
        }
        return ans;
    }
};
