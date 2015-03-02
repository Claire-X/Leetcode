//借鉴了reverse linked list 2中的思路
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head||k<2) return head;
        ListNode dummy(0);
        ListNode* pre= &dummy,*start = head,*end=head;
        pre->next =head;

        int cnt = k;
        while(--cnt) {
            end = end->next;
            if(!end) return dummy.next;
        }

        while(1){
            head = start->next;

            start->next = head->next;
            head->next = pre->next;
            pre->next = head;

            if(end==head){
            	end = start;
                cnt = k;
                while(cnt--) {
                    end = end->next;
                    if(!end) break;
                }
                if(!end) break;
                pre=start;
                start = start->next;
            }
        }

        return dummy.next;
    }
};
//递归
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head||k<2) return head;

        ListNode* next_group=head;
        int cnt=k;
        while(cnt--){
            if(!next_group) return head;
            next_group = next_group->next;
        }
        //cout<<next_group->val<<endl;
        ListNode* new_next = reverseKGroup(next_group,k);//cout<<new_next->val<<endl;
        ListNode* prev=NULL,*cur=head;

        while(cur!= next_group){
            ListNode* next = cur->next;
            cur->next=prev? prev:new_next;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

//另一种iteration，reverseList作为subroutine
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head||k<2) return head;

        ListNode dummy(0);
        ListNode* pre = &dummy,*start = head,*end= head;
        pre->next = head;

        while(1){
        	if(!end) break;
            int cnt=k;
            while(cnt--){
                if(!end) {pre->next=start;return dummy.next;}
                end = end->next;
            }

            ListNode* newHead = reverseList(start,k);
            pre->next=newHead;
            pre = start;
            start=end;
        }
        return dummy.next;
    }

private:
    ListNode* reverseList(ListNode* head,int k){
        ListNode* prev=NULL,*cur=head;
        while(k--){
            ListNode* next = cur->next;
            cur->next=prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
