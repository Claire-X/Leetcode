class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head,*slow=head;
        while(fast){
            fast=fast->next;
            if(fast) fast=fast->next;
            else break;
            slow = slow->next;
            if(slow == fast) break;
        }
        
        if(fast == NULL) return NULL;
        
        fast = head;
        while(fast!=slow){
            fast = fast->next;
            slow=slow->next;
        }
        return slow;
        
    }
};
