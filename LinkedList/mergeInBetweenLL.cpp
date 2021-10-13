//Leetcode solution
//Merge in between a linked list
//Leetcode question no. 1669
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* end = NULL;
        int pos1 = 1;
        int pos2 = 0;
        while(temp->next != NULL){
            if(pos2 == b){
                end = temp->next;
                break;
            }
            pos2++;
            temp = temp->next;
        }
        ListNode* ref1 = list1;
        ListNode* ref2 = list2;
        while(ref1->next != NULL){
            if(pos1 == a){
                ref1->next = ref2;
            }
            pos1++;
            ref1 = ref1->next;
        }
        ref1->next = end;
        return list1;
    }
};
