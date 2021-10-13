//Merge 2 sorted Linked Lists into a sorted Linked List
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
Node* append(Node*** head,int val){
    Node* newnode = new Node(val);
    if(**head == NULL){
        **head = newnode;
    }
    else{
        Node* temp = **head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return **head;
}
Node* getElements(Node** head){
    int m;
    cout<< "Enter size:";
    cin >> m;
    cout<< "Enter the elements:\n";
    for(int j = 0; j < m; j++){
        int o;
        cin >> o;
        append(&head,o);
    }
    return *head;
}
void print(Node* head){
    cout<< "Elements are:\n";
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    }
    cout<< "\n";
}
Node* merge(Node* head1,Node* head2){
    
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    if(head1 == NULL && head2 != NULL) return head2;
    if(head2 == NULL && head1 != NULL) return head1;
    if(head1->data < head2->data){
        head1->next = merge(head1->next,head2);
        return head1;
    }
    else{
        head2->next = merge(head2->next,head1);
        return head2;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m;
    cout<< "Enter no of test cases:";
    cin >> m;
    
    for(int i = 0; i < m; i++){
        cout<< "Test Case No: " << i+1 << "\n";
        Node* head1 = NULL;
        getElements(&head1);
        Node* head2 = NULL;
        getElements(&head2);
        head1 = merge(head1,head2);
        print(head1);
    }
    return 0;
}
