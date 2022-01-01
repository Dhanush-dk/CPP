//Recursive soln
class Solution {
public:
    void bfs(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        bfs(root->left, ans);
        bfs(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        bfs(root, ans);
        return ans;
    }
};



// Iterative soln
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if(root == NULL) return ans;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if(node->right != NULL) s.push(node->right);
            if(node->left != NULL) s.push(node->left);
           
        }
        return ans;
    }
};
