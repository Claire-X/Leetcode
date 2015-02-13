class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root)
			return;
		connect(root, NULL);

	}
private:
	void connect(TreeLinkNode *node, TreeLinkNode *sibling) {
		node->next = sibling;
		if (node->left) {
			connect(node->left, node->right);
			if (sibling) {
				connect(node->right, sibling->left);
				connect(sibling->left, sibling->right);
			}
		}

	}
};
