Leetcode Qn. 863 
All Nodes Distance K in Binary Tree 

class Solution {
public:
    void parentNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL) return ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        parentNode(root, parent);
        
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> queue;
        queue.push(target);
        vis[target] = true;
        int curr_level = 0;
        while(!queue.empty()){
            int n = queue.size();
            if(curr_level++ == k) break;
            while(n--){
                TreeNode* node = queue.front();
                queue.pop();
                if(node->left && !vis[node->left]) {
                    queue.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right]) {
                    queue.push(node->right);
                    vis[node->right] = true;
                }
                if(parent[node] && !vis[parent[node]]) {
                    queue.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
        }
        while(!queue.empty()){
            ans.push_back(queue.front()->val);
            queue.pop();
        }
        return ans;
    }
};
