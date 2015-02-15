class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > result;
		if (!root)
			return result;
		vector<int> row;
		bool flag = false;
		queue<TreeNode*> cur, next;
		cur.push(root);
		while (!cur.empty()) {
			while (!cur.empty()) {
				TreeNode * n = cur.front();
				cur.pop();
				row.push_back(n->val);
				if (n->left)
					next.push(n->left);
				if (n->right)
					next.push(n->right);
			}
			if (flag)
				reverse(row.begin(), row.end());
			result.push_back(row);
			swap(cur, next);
			row.clear();
			flag = !flag;
		}
		return result;
	}
};
