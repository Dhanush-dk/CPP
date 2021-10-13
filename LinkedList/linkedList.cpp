// Basic operations of Linked Lists 
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
};
void push(Node** head,int val){
    Node* newnode = new Node();
    newnode->data = val; 
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
    }
    else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        temp->next = newnode;
    }
}
void insertAtPosition(Node** head,int val,int pos){
    Node* temp = *head;
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    if(pos < 1){
        cout<< "Invalid position.\n";
    }
    else if(pos == 1){
        newnode->next = *head;
        *head = newnode;
    }
    else{
        for(int i = 1; i < pos-1; i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void deleteAtPosition(Node* &head,int pos){
    Node* temp = head;
    if(head == NULL) return;
    if(pos < 1){
        cout<< "Invalid Position\n";
    }
    else if(pos == 1){
        Node* t = head;
        head = head->next;
        delete t;
    }
    else{
        for(int i = 1; i < pos-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
}
void reverse(Node** head){
    cout<< "Reversing elements..\n";
    Node* prev = NULL;
    Node* nextt = NULL;
    Node* curr = *head;
    while(curr != NULL){
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }
    *head = prev;
}
void print(Node* head){
    cout<< "Elements are:\n";
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    }
    cout<< "\n";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    Node* head = NULL;
    int n,pos;
    cout<< "Enter size:";
    cin>> n;
    for(int i = 0; i < n; i++){
        int m;
        cin>> m;
        push(&head,m);
    }
    print(head);
    cout<< "Enter position to insert a node:";
    cin>> pos;
    int newData;
    cout<< "Enter data to insert:";
    cin>> newData;
    insertAtPosition(&head,newData,pos);
    print(head);
    int pos1;
    cout<< "Enter position to delete a node:";
    cin>> pos1;
    deleteAtPosition(head,pos1);
    print(head);
    reverse(&head);
    print(head);
    return 0;
}
