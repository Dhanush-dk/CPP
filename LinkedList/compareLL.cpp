//Compare 2 linked lists
#include <bits/stdc++.h>
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
int compare(Node* head1,Node* head2){
    if(head1 == NULL && head2 == NULL) return 1;
    else if(head1 == NULL || head2 == NULL) return 0;
    else{
        if(head1->data == head2->data){
            compare(head1->next,head2->next);
        }
        else 
            return 0;
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
int main() {  
    
    int n;
    cout<< "Enter no of test cases:";
    cin >> n;
    
    for(int i = 0; i < n ; i++){
        cout<< "Test Case No: " << i+1 << "\n";
        Node* head1 = NULL;
        getElements(&head1);
        Node* head2 = NULL;
        getElements(&head2);
        cout<< "Result = " << compare(head1,head2) << "\n";
    }
    return 0;
}
