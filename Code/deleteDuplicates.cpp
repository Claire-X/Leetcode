class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head)
			return nullptr;
		auto it = head;

		while (it->next) {

			auto r = it;
			while (it->next && it->val == it->next->val) {
				it = it->next;
			}

			if (r == it) {
				it = it->next;
			} else if (it->next) {
				it = it->next;
				r->next = it;
			} else {
				r->next = NULL;
			}
		}

		return head;
	}
};
