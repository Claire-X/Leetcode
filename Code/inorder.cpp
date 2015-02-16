//recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder(result,root);
        return result;
    }
    void inorder(vector<int>& result,TreeNode *root){
        if(!root) return;
        inorder(result,root->left);
        result.push_back(root->val);
        inorder(result,root->right);
    }
};

//iteration
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if (!root)
			return result;
		stack<pair<TreeNode*, int> > stk;
		stk.push(make_pair(root, 1));
		while (!stk.empty()) {
			TreeNode* n = stk.top().first;
			int count = stk.top().second;
			if (count == 1) {
				stk.top().second++;
				if (n->left)
					stk.push(make_pair(n->left, 1));
				continue;
			}
			if (count == 2) {
				stk.pop();
				result.push_back(n->val);
				if (n->right)
					stk.push(make_pair(n->right, 1));
			}
		}
		return result;

	}
};
