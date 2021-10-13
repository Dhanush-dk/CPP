//Inserting a Node into a sorted Doubly Linked List
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        Node* prev;
        int data;
        Node* next;

        Node(int val){
            prev = NULL;
            data = val;
            next = NULL;
        }
};
void insert(Node** head,Node** tail,int val){
    Node* newnode = new Node(val);
    if(*head == NULL){
        *head = newnode;
        *tail = newnode;
    }
    else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        *tail = newnode;
    }
}
Node* insertNewNode(Node* head,int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        return head;
    }
    if(head->data > val){
        newnode->next = head;
        head->prev = newnode;
        return newnode;
    }
    else {
        Node* current = head;
        while (current->next != NULL && current->next->data < newnode->data)
            current = current->next;
        newnode->next = current->next;
        if (current->next != NULL)
            newnode->next->prev = newnode;
        current->next = newnode;
        newnode->prev = current;
    }
    return head;
}
void print(Node* head){
    cout<< "Printing the elements using head:\n";
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    }
    cout<< "\n";
}
int main(){
    cout<<"Enter No of elements to insert in DLL:";
    int n;
    cin>> n;
    Node* head = NULL;
    Node* tail = NULL;
    cout<< "Enter elements:\n";
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        insert(&head,&tail,m);
    }
    int p;
    cout<< "Enter a node data to insert:";
    cin >> p;
    head = insertNewNode(head,p);
    print(head);
    return 0;
}