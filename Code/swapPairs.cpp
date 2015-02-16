class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if (!head)
			return NULL;
		if (!head->next)
			return head;

		ListNode *pre = new ListNode(0), *tail = new ListNode(0);
		bool flag = true;
		pre->next = head;
		ListNode *i = head, *j = head->next, *back = head->next->next;
		head = pre;
		if (back == NULL) {
			head->next->next = tail;
			back = tail;
			flag = false;
		}

		while (flag) {
			pre->next = j;
			j->next = i;
			i->next = back;
			pre = i;
			i = back;
			j = back->next;
			if (j == NULL)
				break;
			if (j->next == NULL) {
				j->next = tail;
				flag = false;
			}
			back = j->next;
		}
		if (!flag) {
			pre->next = j;
			j->next = i;
			i->next = NULL;
			delete back;
		}

		return head->next;

	}
};
