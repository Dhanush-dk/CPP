// Using Reverse Preorder traversal
// i.e. Root Right Left

class Solution {
public:
    void revPreorder(TreeNode* root, int level, vector<int> &ans){
        if(root == NULL) return;
        if(level == ans.size()) 
            ans.push_back(root->val);
        revPreorder(root->right, level+1, ans);
        revPreorder(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        revPreorder(root, 0, ans);
        return ans;
    }
};
