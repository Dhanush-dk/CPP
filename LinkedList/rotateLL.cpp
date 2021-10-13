//Rotate Linked List right by K positions
//Leetcode solution

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int length = 1;
        ListNode *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            length++;
        }
        temp->next = head;
        k = k % length;
        k = length - k;
        while(k--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
