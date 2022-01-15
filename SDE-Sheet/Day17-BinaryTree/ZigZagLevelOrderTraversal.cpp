class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        int flag = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ds;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                ds.push_back(node->val);
            }
            if(flag == 0){
                ans.push_back(ds);
                flag = 1;
            }
            else{
                reverse(ds.begin(), ds.end());
                ans.push_back(ds);
                flag = 0;
            }
        }
        return ans;
    }
};

//Optimized code
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        bool flag = true;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ds(size);
            int i = 0;
            while(i < size){
                TreeNode* node = q.front();
                q.pop();
                int index = (flag == true) ? i : (size - i - 1);
                ds[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                i++;
            }
            flag = !flag;
            ans.push_back(ds);
        }
        return ans;
    }
};
