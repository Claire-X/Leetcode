//second
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        fla(root);
    }
    
    TreeNode* fla(TreeNode* root){

        TreeNode* l=root->left,*r=root->right;
        if(!l&&!r) return root;
        if(l&&r){
            root->left=NULL;
            root->right = l;
            fla(l)->right = r;
            return fla(r);
        }
        if(!l&&r){
            return fla(r);
        }
        if(l&&!r){
            root->left = NULL;
            root->right = l;
            return fla(l);
        }
    }
};
//first
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
