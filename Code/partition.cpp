//second
// anchor means the first element that is greater than or equal to x. After anchor is found in the later loop,
//each time we found an element that is less than x, we insert it after the anchor, and move anchor by one step.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0),*pre = &dummy,*anchor=NULL;
        dummy.next = head;
        for(;head;pre=head,head=head->next){
            if(!anchor){
                if(head->val>=x) 
                    anchor = pre;
                else continue;
            }else if(head->val<x){
                    pre->next = head->next;
                    head->next = anchor->next;
                    anchor->next = head;
                    anchor = anchor->next;
                    head = pre;
            }
        }
        return dummy.next;
    }
};
//first reference to Leetcode详解
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
