//Recursion soln

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l,r);
    }
};

// Iterative soln using level order traversal
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        int depth = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
