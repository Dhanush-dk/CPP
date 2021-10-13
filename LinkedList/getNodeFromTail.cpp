//Return a node data counting from the tail of the linked list
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    
        Node(int val){
            data = val;
            next = NULL;
    }
};
void insert(Node** head,int val){
    Node* newnode = new Node(val);
    if(*head == NULL){
        *head = newnode;
    }
    else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void print(Node* head){
    cout<< "Elements are:\n";
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    }
    cout<< "\n";
}
int getData(Node* head,int pos){
    Node* main = head;
    Node* ref = head;
    while(pos >= 2){
        ref = ref->next;
        pos--;
    }
    while(ref->next != NULL){
        ref = ref->next;
        main = main->next;
    }
    return main->data;
}
int main(){
    int n;
    cout<< "Enter no of nodes:";
    cin>> n;
    Node* head = NULL;
    cout<< "Enter nodes:\n";
    for(int i = 0; i < n; i++){
        int m;
        cin>> m;
        insert(&head,m);
    }
    int pos;
    cout<< "Enter pos from tail:";
    cin >> pos;
    int result = getData(head,pos);
    cout<< "Result = " << result << "\n";
    return 0;
}