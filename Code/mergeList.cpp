class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        
        ListNode head(0);
        ListNode *pre=&head;
        
         
        while(l1&&l2){
            if(l1->val<l2->val){
                pre->next=l1;
                pre=pre->next;
                l1=l1->next;
            }
            else{
                pre->next=l2;
                pre=pre->next;
                l2=l2->next;
            } 
        }
        
        if(l1) pre->next=l1;
        if(l2) pre->next=l2;
        
        return head.next;
    }
};
