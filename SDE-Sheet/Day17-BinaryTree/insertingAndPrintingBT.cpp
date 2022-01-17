// Creating Binary Tree by giving user inputs...
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Tree{
    public:
        int val;
        Tree* left;
        Tree* right;
        
        Tree(int data){
            val = data;
            left = NULL;
            right = NULL;
        }
};
void insertIntoTree(int data, Tree** root, queue<Tree*>&q){
    Tree* node = new Tree(data);
    if(*root == NULL){
        *root = node;
    }
    else if(!q.front()->left){
            q.front()->left = node;
    }
    else{
        q.front()->right = node;
        q.pop();
    }
    q.push(node);
}
void print(Tree* root){
    cout<< "\nLevel order traversal...\n";
    if(root == NULL) {
        cout<< "Empty";
        return;
    }
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        Tree* node = q.front();
        q.pop();
        cout<< node->val << " ";
        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
}
void inorder(Tree* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<< root->val << " ";
    inorder(root->right);
}
int main()
{
    Tree* root = NULL;
    queue<Tree*> q;
    int n;
    cout << "Enter size:";
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        insertIntoTree(k, &root, q);
    }
    print(root);
    cout<< "\nPrinting inorder traversal...\n";
    inorder(root);
    return 0;
}

//Creating Binary Tree using vector elements...
#include <bits/stdc++.h>
using namespace std;
class Tree{
  public:
    int data;
    Tree* left;
    Tree* right;
    
    Tree(int val){
        data = val;
        left = NULL;
        right = NULL; 
    }
};
void insert(int val, Tree*** root, queue<Tree*> &q){
    Tree* node = new Tree(val);
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
void createTree(vector<int> v, Tree** root){
    int size = v.size();
    queue<Tree*> q;
    for(int i = 0; i < size; i++)
        insert(v[i], &root, q);
}
void print(Tree* root){
    cout<< "Printing level order...\n";
    queue<Tree*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Tree* temp = q.front();
            q.pop();
            cout<< temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    cout << "\n";
}
void printInorder(Tree* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout<< root->data << " ";
    printInorder(root->right);
}
int main() {
    vector<int> v{1,2,3,4,5,6,7};
    Tree* root = NULL;
    createTree(v, &root);
    print(root);
    cout<< "Printing Inorder Traversal..\n";
    printInorder(root);
    return 0;
}
