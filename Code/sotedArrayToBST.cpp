class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.size() == 0)
			return NULL;
		TreeNode* root = new TreeNode(num[num.size() / 2]);
		if (num.size() == 1)
			return root;
		vector<int> l(num.begin(), num.begin() + num.size() / 2);
		vector<int> r(num.begin() + num.size() / 2 + 1, num.end());
		root->left = sortedArrayToBST(l);
		root->right = sortedArrayToBST(r);
		return root;

	}
};
