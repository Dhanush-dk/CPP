//Find Merge Point of Two Linked Lists and Get the Node data
//HackerRank Soln

int count(SinglyLinkedListNode* head){
    SinglyLinkedListNode* temp = head;
    int count = 0;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
int getData(SinglyLinkedListNode* head1,SinglyLinkedListNode* head2,int diff){
    SinglyLinkedListNode* temp1 = head1;
    while(diff > 0){
        if(temp1->next == NULL) return -1;
        temp1 = temp1->next;
        diff--;
    }
    SinglyLinkedListNode* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(&temp1->data == &temp2->data && temp1->data == temp2->data){
            return temp1->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1 == NULL || head2 == NULL) return 0;
    int c1 = count(head1);
    int c2 = count(head2);
    if(c1 > c2 || c1 == c2){
        int diff = c1 - c2;
        return getData(head1,head2,diff);
    }
    else{
        int diff = c2 - c1;
        return getData(head2,head1,diff);
    }
    return -1;
}