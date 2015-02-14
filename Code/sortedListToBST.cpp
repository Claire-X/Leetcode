class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {

		if (!head)
			return NULL;
		if (head->next == NULL)
			return new TreeNode(head->val);

		ListNode* node = head;
		int i = 1;
		while (node = node->next)
			i++;
		i /= 2;
		node = head;
		while (--i)
			node = node->next;

		ListNode* tmp = node->next;
		node->next = NULL;

		TreeNode* root = new TreeNode(tmp->val);
		root->right = sortedListToBST(tmp->next);
		root->left = sortedListToBST(head);

		return root;

	}
};
