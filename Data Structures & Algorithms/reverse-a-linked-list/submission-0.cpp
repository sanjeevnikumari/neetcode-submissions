

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextTemp = curr->next; // store next node
            curr->next = prev;               // reverse pointer
            prev = curr;                     // move prev forward
            curr = nextTemp;                 // move curr forward
        }

        return prev; // new head
    }
};
