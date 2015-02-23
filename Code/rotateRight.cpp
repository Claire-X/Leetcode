/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head||!head->next||k==0) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode *l=head,*r=head;
        
        int n=0;
        while(r){
            r=r->next;
            n++;
        }
        k%=n;
        if(k==0) return head;
        int count = k;
        r=head;
        while(r->next){
            r=r->next;
            if(!count) l=l->next;
            if(count>0) count--;
            
        }
        ListNode *begin = l->next;
        l->next = NULL;
        r->next = dummy.next;
        dummy.next = begin;
        return dummy.next;
        
    }
};
