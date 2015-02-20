class Solution {
public:
    ListNode *partition(ListNode *head, int x) {

        ListNode dummyLeft(0),dummyRight(0);
        ListNode *left = &dummyLeft,*right = &dummyRight;
        for(;head;head=head->next){
            if(head->val < x ){
                left->next = head;
                left=head;}
            else{
                right->next = head;
                right= head;
            }
        }
        right->next=NULL;
        left->next = dummyRight.next;
        return dummyLeft.next;
    }
};
