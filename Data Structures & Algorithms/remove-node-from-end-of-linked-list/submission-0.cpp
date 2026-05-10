class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // move fast n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // move both until fast reaches end
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // delete node
        slow->next = slow->next->next;

        return dummy->next;
    }
};