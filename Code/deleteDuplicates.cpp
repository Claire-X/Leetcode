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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return nullptr;
        auto it=head;

        while(it->next){
           
           auto r=it;
           while(it->next && it->val == it->next->val){
             it=it->next;
           }
           
           if(it->next){
               it=it->next;
               r->next=it;
           } else {r->next=NULL;}
        }
        
        return head;
    }
};
