//space O(n) trival inorder traverse
class Solution {
public:
    void recoverTree(TreeNode *root) {
        if(!root) return;
        stack<pair<TreeNode*,int> > stk;
        TreeNode* pre=NULL,*left=NULL,*right=NULL;
        stk.push(make_pair(root,1));
        while(!stk.empty()){
            int count = stk.top().second;
            TreeNode *n = stk.top().first;
            if (count){
                stk.top().second--;
                if(n->left) stk.push(make_pair(n->left,1));
            }else{
                stk.pop();
                if(n->right) stk.push(make_pair(n->right,1));
                if(pre&&pre->val>n->val){
                    if(!left) {left = pre;right= n;}
                    else right = n;
                }
                pre = n;
            }
        }
        swap(left->val,right->val);
    }
};

//space(1)
class Solution {
public:
	void recoverTree(TreeNode *root) {
		TreeNode* cur = root, *first = NULL, *last = NULL, *pre;
		while (cur) {
			if (cur->left) {
				TreeNode* tmp = cur->left;
				while (tmp->right && tmp->right != cur)
					tmp = tmp->right;
				if (!tmp->right) {
					tmp->right = cur;
					cur = cur->left;
				} else {
					if (pre&&cur->val < pre->val) {
						if (!first)
							first = pre;
						last = cur;
					}
					pre = cur;
					tmp->right = NULL;
					cur = cur->right;

				}
			    } else {
				    if (pre&& cur->val < pre->val) {
					    if (!first)
						    first = pre;
					    last = cur;
				    }
				    pre = cur;
					cur = cur->right;
			}
		}
		swap(first->val,last->val);
	}
};
