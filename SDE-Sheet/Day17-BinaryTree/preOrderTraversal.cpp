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
