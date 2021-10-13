//Check if there is a loop in Linked list
//Returns 1 if there is a loop else returns 0
int checkLoop(Node* head){
    if(head == NULL)
        return 0;
    Node* slow = head;
    Node* fast = head;
    while(slow->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL) return 0;
        if(slow == fast)
            return 1;
    }
    return 0;
}