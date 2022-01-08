class Solution {
public:
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;
        
        int l = dfsHeight(root->left);
        if(l == -1) return -1;
        
        int r = dfsHeight(root->right);
        if(r == -1) return -1;
        
        if(abs(l-r) > 1) return -1;
        
        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};
