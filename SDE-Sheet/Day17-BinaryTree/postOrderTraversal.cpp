//Recursive soln
class Solution {
public:
    void bfs(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        bfs(root->left, ans);
        bfs(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        bfs(root, ans);
        return ans;
    }
};

// Iterative soln using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s;
        stack<TreeNode*> ss;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            ss.push(node);
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        while(!ss.empty()){
            ans.push_back(ss.top()->val);
            ss.pop();
        }
        return ans;
    }
};
