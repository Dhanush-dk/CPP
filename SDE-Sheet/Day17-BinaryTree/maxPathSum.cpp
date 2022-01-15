class Solution {
public:
    int findMaxPath(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        int left = max(0,findMaxPath(root->left, maxi));
        int right = max(0,findMaxPath(root->right, maxi));
        maxi = max(maxi, left + right + root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPath(root, maxi);
        return maxi;
    }
};
