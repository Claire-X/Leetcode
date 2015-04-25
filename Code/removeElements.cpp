class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0),*pre = &dummy;
        dummy.next = head;
        
        while(head){
            if(head->val==val){
                pre->next = head->next;
                delete head;
                head = pre->next;
            }else{
                pre = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};
