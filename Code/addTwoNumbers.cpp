class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry=0;
        ListNode head(0);
        ListNode* p=&head;
        for(;l1||l2;p=p->next){
            int op1 = l1? l1->val:0;
            int op2 = l2?l2->val:0;
            int digit = (op1+op2+carry)%10;
            carry = (op1+op2+carry)/10;
            p->next = new ListNode(digit);
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry) p->next = new ListNode(carry);
        return head.next;
    }
};
