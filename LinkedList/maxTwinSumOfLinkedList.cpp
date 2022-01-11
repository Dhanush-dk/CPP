class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        stack<int> s;
        while(fast != NULL){
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        int maxSum = INT_MIN;
        while(slow != NULL){
            maxSum = max(maxSum, s.top() + slow->val);
            s.pop();
            slow = slow->next;
        }
        return maxSum;
    }
};
