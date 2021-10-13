//Basic Operations on Doubly Linked List
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
void push(Node** head,Node** tail,int val){
    Node* newnode = new Node(val);
    if(*head == NULL){
        *head = newnode;
        *tail = newnode;
        return;
    }
    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;
}
void append(Node** head,Node** tail,int val){
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
void insertAfter(Node** prev_node,int val){
    Node* newnode = new Node(val);
    if(*prev_node == NULL) return;
    if((*prev_node)->next == NULL){
        (*prev_node)->next = newnode;
        newnode->prev = (*prev_node);
        return;
    }
    newnode->next = (*prev_node)->next;
    (*prev_node)->next = newnode;
    newnode->prev = (*prev_node);
    newnode->next->prev = newnode;
}
void deleteAtFirst(Node** head){
    if(*head == NULL) return;
    Node* ptr = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(ptr);
    cout<< "Deleted\n";
}
void deleteAtEnd(Node** tail){
    if(*tail == NULL) return;
    Node* ptr = *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    free(ptr);
    cout<< "Deleted\n";
}
void deleteGivenNode(Node** head,Node* del_node){
    if(del_node == NULL) return;
    Node* temp = *head;
    //Node* del = del_node;
    while(temp != del_node){
        temp = temp->next;
    }
    if(del_node->next != NULL) del_node->next->prev = del_node->prev;
    if(del_node->prev != NULL) del_node->prev->next = del_node->next;
    free(del_node);
    cout<< "Deleted\n";
}
void deleteGivenNodeWithoutPointer(Node* del){
    if(del == NULL) return;
    if(del->next == NULL){
        cout<< "This is the last node. Can't delete it.\n";
        return;
    }
    Node* temp = del->next;
    del->data = del->next->data;
    del->next = del->next->next;
    free(temp);
    cout<< "Deleted\n";
}
void deleteAtPosition(Node** head,int pos){
    if(*head == NULL || pos < 1){
        cout<< "Underflow!!\n";
        return;
    }
    Node* temp = *head;
    int i = 1;
    while(pos > 1){
        temp = temp->next;
        pos--;
    }
    if(temp->next == NULL){
        temp->prev->next = NULL;
        free(temp);
        cout<< "Deleted\n";
        return;
    }
    deleteGivenNodeWithoutPointer(temp);

}
void print(Node* head){
    cout<< "Printing the elements using head:\n";
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    }
    cout<< "\n";
}
void printReverse(Node* tail){
    cout<< "Printing the elements in reverse using tail:\n";
    while(tail != NULL){
        cout<< tail->data << " ";
        tail = tail->prev;
    }
    cout<< "\n";
}
int main(){
    int size;
    cout<< "Enter the no of elements to append to the list:";
    cin >> size;
    Node* head = NULL;
    Node* tail = NULL;
    cout<< "Enter elements:\n";
    for(int i = 0; i < size; i++){
        int num;
        cin >> num;
        append(&head,&tail,num);
    }
    print(head);
    int p;
    cout<< "Enter the no of elements to push into the list:";
    cin >> p;
    cout<< "Enter elements:\n";
    for(int i = 0; i < p; i++){
        int q;
        cin >> q;
        push(&head,&tail,q);
    }
    print(head);
    printReverse(tail);
    insertAfter(&head->next,111);
    print(head);
    deleteAtFirst(&head);
    print(head);
    deleteAtEnd(&tail);
    print(head);
    deleteGivenNode(&head,head->next->next);
    print(head);
    deleteGivenNodeWithoutPointer(head->next->next);
    print(head);
    deleteAtPosition(&head,4);
    print(head);
    return 0;
    
}
