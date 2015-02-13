class Solution {
public:
	void flatten(TreeNode *root) {
		dfs(root);
	}

private:
	TreeNode* dfs(TreeNode *root) {
		if (!root)
			return NULL;
		if (!root->left && !root->right)
			return root;
		TreeNode* l = root->left, *r = root->right, *connect = NULL;
		if (l) {
			root->left = NULL;
			root->right = l;
			connect = dfs(l);
		}
		if (connect)
			connect->right = r;

		return dfs(root->right);
	}
};
