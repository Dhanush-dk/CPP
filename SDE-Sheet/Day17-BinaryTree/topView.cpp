class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int n = it.second;
            if(m.find(n) == m.end()) m[n] = node->data;
            if(node->left != NULL){
                q.push({node->left, n-1});
            }
            if(node->right != NULL){
                q.push({node->right, n+1});
            }
        }
        for(auto i: m){
            ans.push_back(i.second);
        }
    }
};
