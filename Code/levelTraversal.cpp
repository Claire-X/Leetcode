class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {

		vector<vector<int> > result;
		if (root == NULL)
			return result;
		vector<int> current;
		queue<pair<TreeNode*, int> > q;
		q.push(make_pair(root, 0));
		int pre = 0;
		while (!q.empty()) {
			TreeNode* n = q.front().first;
			int depth = q.front().second;
			q.pop();
			if (n->left)
				q.push(make_pair(n->left, depth + 1));
			if (n->right)
				q.push(make_pair(n->right, depth + 1));
			if (depth != pre) {
				result.push_back(current);
				current.clear();
			}
			current.push_back(n->val);
			if (q.empty())
				result.push_back(current);
			pre = depth;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
