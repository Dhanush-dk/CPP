// Returns True if palindrome else False
// Leetcode solution
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while(temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        while(head != NULL){
            if(s.top()==head->val) s.pop();
            else return false;
            head = head->next;
        }
        if(s.empty()) return true;
        else return false;
    }
};
