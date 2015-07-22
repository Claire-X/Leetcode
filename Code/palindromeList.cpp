class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode dummy(0);
        dummy.next = head; 
        ListNode* slow = &dummy,*fast = &dummy;
        while(fast->next&&fast->next->next){
            slow  = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow);
        fast = dummy.next;
        while(slow && fast){
            if(slow->val!=fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* pre = NULL,*tmp;
        while(head){
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};
