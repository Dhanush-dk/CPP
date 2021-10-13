//Remove duplicates from sorted Linked list
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
void removeDuplicates(Node** head){
    if(*head == NULL) return;
    Node* dup = *head;
    Node* main = *head;
    dup = dup->next;
    while(main->next != NULL){
        if(main->data != dup->data){
            dup = dup->next;
            main = main->next;
        }
        else{
            Node* temp = dup->next;
            main->next = temp;
            dup = dup->next;
        }
    }
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
    removeDuplicates(&head);
    print(head);
}

//Leetcode Solution
//Short solution than the above one
ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL) return head;
    ListNode* ref = head;
    ListNode* temp = head;
    ref = ref->next;
    while(temp->next != NULL){
        if(temp->val == ref->val) temp->next = ref->next;
        else temp = temp->next;
        ref = ref->next;
    }
    return head;
}
