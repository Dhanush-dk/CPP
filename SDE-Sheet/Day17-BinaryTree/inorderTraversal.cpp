// Recursive soln
class Solution {
public:
    void bfs(TreeNode* root, vector<int> &ans){
        if(root == NULL) return;
        bfs(root->left, ans);
        ans.push_back(root->val);
        bfs(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        bfs(root, ans);
        return ans;
    }
};


//Iterative soln 1
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        TreeNode *currNode = root;
        while(currNode || !st.empty()){
            while(currNode != NULL){
                st.push(currNode);
                currNode = currNode->left;
            }
            currNode = st.top();
            st.pop();
            ans.push_back(currNode->val);
            currNode = currNode->right;
        }
        return ans;
    }
};


// Iterative soln 2
class Solution {

public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s; 
        TreeNode* node = root;
        vector<int> ans; 
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); 
                st.pop(); 
                ans.push_back(node->val); 
                node = node->right; 
            }  
        }
        return ans; 
    }
};
