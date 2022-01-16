class Solution {
public:
    int findLeftHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }
        return height;
    }
    int findRightHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l = findLeftHeight(root);
        int r = findRightHeight(root);
        if(l == r) return pow(2,r)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
