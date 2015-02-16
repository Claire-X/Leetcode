class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (!head || !head->next)
			return head;
		int length = 1;
		ListNode *p = head;
		while (p = p->next)
			length++;
		return sortList(head, length);
	}
private:
	ListNode *sortList(ListNode *head, int length) {
		if (!head || !head->next)
			return head;
		ListNode *it = head;
		int lsize = length / 2;
		while (--lsize)
			it = it->next;
		ListNode *tmp = it->next;
		it->next = NULL;

		ListNode *left = sortList(head, length / 2);
		ListNode *right = sortList(tmp, length - length / 2);

		ListNode front(0);
		
		for (ListNode *pre = &front; left || right; pre = pre->next) {
			int l = left?left->val:INT_MAX;
			int r = right?right->val:INT_MAX;
			if (l <= r) {
				pre->next = left;
				left = left->next;
			} else {
				pre->next = right;
				right = right->next;
			}
		}
		return front.next;
	}
};
