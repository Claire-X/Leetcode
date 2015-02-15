class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(),
				inorder.end());
    }

private:

	TreeNode *buildTree(vector<int>::iterator pb, vector<int>::iterator pe,
			vector<int>::iterator ib, vector<int>::iterator ie) {
		if (distance(ib, ie) == 0)
			return NULL;

		TreeNode *root = new TreeNode(*pb);
		if (distance(ib, ie) == 1)
			return root;

		auto i = find(ib, ie, *pb);
		int leftsize = distance(ib, i), rightsize = distance(ib, ie) - leftsize
				- 1;

		if (leftsize > 0)
			root->left = buildTree(pb+1, pb + leftsize+1,ib, i);

		if (rightsize > 0)
			root->right = buildTree(pb + leftsize+1, pe,i + 1, ie);

		return root;

	}
};
