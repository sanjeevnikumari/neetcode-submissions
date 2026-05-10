class Solution {
public:

    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail;
        ListNode* curr = head;
        while(curr != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;
        
        while(true) {
            ListNode* kth = groupPrev;
            // find k-th node
            for(int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if(!kth) break;
            ListNode* groupNext = kth->next;
            ListNode* groupStart = groupPrev->next;
            // reverse group
            ListNode* newHead = reverse(groupStart, groupNext);

            groupPrev->next = newHead;
            groupStart->next = groupNext;

            groupPrev = groupStart;
        }
        return dummy->next;
    }
};