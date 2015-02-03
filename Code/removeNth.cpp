class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode* h = new ListNode(0);
		h->next = head;
		ListNode *p = h, *q = h;

		for (int i = 0; i < n; i++)
			p = p->next;
		while (p->next != NULL) {
			p = p->next;
			q = q->next;
		}

		ListNode* tmp = q->next;
		q->next = tmp->next;
		delete tmp;

		return h->next;
	}
};
