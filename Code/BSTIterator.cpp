class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root) {
			stk.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !stk.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *n = stk.top();
		stk.pop();
		if (n->right) {
			TreeNode* r = n->right;
			stk.push(r);
			while (r->left) {
				stk.push(r->left);
				r = r->left;
			}
		}
		return n->val;
	}

private:
	stack<TreeNode*> stk;
};
