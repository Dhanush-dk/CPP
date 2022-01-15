class Solution {
public:
    bool isLeafNode(Node* root){
        return !root->left && !root->right;
    }
    void findLeftBoundary(Node* root, vector<int> &ans){
        Node* cur = root->left;
        while(cur){
            if(!isLeafNode(cur)) ans.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
        return;
    }
    void addLeafNodes(Node *root, vector<int> &ans){
        if(isLeafNode(root)){ 
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeafNodes(root->left, ans);
        if(root->right) addLeafNodes(root->right, ans);
    }
    void addRightBoundary(Node *root, vector<int> &ans){
        Node* cur = root->right;
        stack<int> s;
        while(cur){
            if(!isLeafNode(cur)) s.push(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return;
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        ans.push_back(root->data);
        findLeftBoundary(root, ans);
        addLeafNodes(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};
