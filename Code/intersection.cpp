class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return nullptr;
		vector<int> la, lb;
		ListNode* it = headA;
		while (1) {
			la.push_back(it->val);
			if (it->next == NULL)
				break;
			it = it->next;
		}
		it = headB;
		while (1) {
			lb.push_back(it->val);
			if (it->next == NULL)
				break;
			it = it->next;
		}
		int i = la.size() - 1;
		int j = lb.size() - 1;
		while (1) {
			if (i < 0) {
				i++;
				j++;
				break;
			}

			if (j < 0) {
				j++;
				i++;
				break;
			}

			if (la[i] != lb[j]) {
				i++;
				j++;
				break;
			}
			i--;
			j--;
		}
		if (i == la.size())
			return nullptr;
		it = headA;

		while (i > 0) {
			it = it->next;
			i--;
		}
		return it;

	}
};
