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

