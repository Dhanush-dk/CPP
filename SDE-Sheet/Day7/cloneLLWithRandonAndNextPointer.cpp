class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return NULL;
        Node *temp = head;
        Node *front = head;
        while(temp != NULL){
            front = temp->next;
            Node *a = new Node(temp->val);
            temp->next = a;
            a->next = front;
            temp = front;
        }
        Node *iter = head;
        while(iter != NULL){
            if(iter->random != NULL) iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        Node *dummy = new Node(0);
        Node *iter1 = head;
        Node *copy = dummy;
        while(iter1 != NULL){
            front = iter1->next->next;
            copy->next = iter1->next;
            iter1->next = front;
            copy = copy->next;
            iter1 = front;
        }
        return dummy->next;
    }
};