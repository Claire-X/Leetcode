//second
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode dummy(0),*pre = head;
        dummy.next = head;
        head = head->next;
        while(head){
            if(head->val>=pre->val) {
                pre=head;
                head=head->next;
                continue;
            }
            pre->next = head->next;
            ListNode *pos = &dummy;
            while(pos->next->val<head->val)
                pos = pos->next;
            head->next = pos->next;
            pos->next = head;
            head = pre->next;
        }
        return dummy.next;
    }
};
//first
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = head,*p = head->next;
        int curlen = 1;
        while(p){
            ListNode* it = dummy.next,*pre = &dummy;
            for(int i = 0;i<curlen;i++){
                if(p->val < it->val) break;
                pre = it;
                it = it->next;
            }
            if(it != p){
                pre->next = p;
                prev->next = p->next;
                p->next = it;
                p = prev->next;
            }else{
                prev = p;
                p= p->next;
            }
            curlen++;
        }
        return dummy.next;
    }
};
