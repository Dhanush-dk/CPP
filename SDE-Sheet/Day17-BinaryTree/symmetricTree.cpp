class Solution {
public:
    bool check(TreeNode* l, TreeNode* r){
        if(l == NULL || r == NULL) return r == l;
        if(l->val != r->val) return false;
        return check(l->left, r->right) && check(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || check(root->left, root->right);
    }
};
