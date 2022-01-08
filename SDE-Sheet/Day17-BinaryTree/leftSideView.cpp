//GFG
void preOrder(struct Node* root, int level, vector<int> &ans){
    if(root == NULL) return;
    if(ans.size() == level) ans.push_back(root->data);
    preOrder(root->left, level+1, ans);
    preOrder(root->right, level+1, ans);
}
vector<int> leftView(Node *root){
   vector<int> ans;
   preOrder(root, 0, ans);
   return ans;
}
