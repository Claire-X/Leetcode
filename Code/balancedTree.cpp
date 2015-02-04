class Solution {
public:
	bool isBalanced(TreeNode *root) {
		if (root == NULL)
			return true;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* r = q.front();
			q.pop();
			if (abs(maxDepth(r->right) - maxDepth(r->left)) > 1)
				return false;
			if (r->right)
				q.push(r->right);
			if (r->left)
				q.push(r->left);
		}

		return true;
	}

private:

	int maxDepth(TreeNode *root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		else if (root->left == NULL)
			return maxDepth(root->right) + 1;
		else if (root->right == NULL)
			return maxDepth(root->left) + 1;
		else
			return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
	}
};
