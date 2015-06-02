//iteration
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head||!head->next) return head;
        ListNode *root = new ListNode(0),*pre=root;
        root->next = head;
        while(head->next){
            if(head->val == head->next->val){
                int mark = head->val;
                while(head && head->val == mark){
                    pre->next = head->next;
                    delete head;
                    head = pre->next;
                }
                if(!head) return root->next;
            }else {
                pre=head;
                head = head->next;
            }
        }
        return root->next;
    }
};
//recursion
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head||!head->next) return head;
 
        if(head->val == head->next->val){
            int mark = head->val;
            while(head && head->val == mark){
                ListNode* tmp = head->next;
                delete head;
                head = tmp;
            }
            return deleteDuplicates(head);
        } else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
