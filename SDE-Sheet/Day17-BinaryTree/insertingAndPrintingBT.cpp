#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL; 
    }
};
Node* insert(int val, Node*** root, queue<Node*> &q){
    Node* node = new Node(val);
    if(**root == NULL) **root = node;
    else if(q.front()->left == NULL){
        q.front()->left = node;
    }
    else{
        q.front()->right = node;
        q.pop();
    }
    q.push(node);
}
void createTree(vector<int> v, Node** root){
    int size = v.size();
    queue<Node*> q;
    for(int i = 0; i < size; i++)
        insert(v[i], &root, q);
}
void print(Node* root){
    cout<< "Printing level order...\n";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* temp = q.front();
            q.pop();
            cout<< temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    cout << "\n";
}
void printInorder(Node* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout<< root->data << " ";
    printInorder(root->right);
}
int main() {
    vector<int> v{1,2,3,4,5,6,7};
    Node* root = NULL;
    createTree(v, &root);
    print(root);
    cout<< "Printing Inorder Traversal..\n";
    printInorder(root);
    return 0;
}
