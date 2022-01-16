class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int min = q.front().second;
            int first, last;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                int index = q.front().second - min;
                q.pop();
                if(i == 0) first = index;
                if(i == size-1) last = index;
                if(node->left) q.push({node->left, index*2 + 1});
                if(node->right) q.push({node->right, index*2 + 2});
            }
            width = max(width, last-first+1);
        }
        return width;
    }
};
