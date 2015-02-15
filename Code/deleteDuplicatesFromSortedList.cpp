//iteration
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next)
			return head;
		ListNode *root = new ListNode(0), *pre;
		root->next = head;
		pre = root;
		while (head->next) {
			if (head->val == head->next->val) {
				int mark = head->val;
				while (head && head->val == mark) {
					ListNode *tmp = head;
					head = head->next;
					pre->next = head;
					delete tmp;
				}
				if (!head)
					return root->next;
			} else {
				pre = pre->next;
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
