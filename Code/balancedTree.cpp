//dfs O(n)
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return balance(root)!=-1;
    }
    int balance(TreeNode* root){
        if(!root) return 0;
        
        int left = balance(root->left);
        if(left==-1) return -1;
        
        int right = balance(root->right);
        if(right==-1) return -1;
        
        if(abs(left-right)>1) return -1;
        else return max(left,right)+1;
    }
}; 

//second recursion O(n2)
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(!root) return true;
        if(isBalanced(root->right)&&isBalanced(root->left)&&abs(depth(root->right)-depth(root->left))<=1) return true;
        else return false;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
}; 

//first
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
