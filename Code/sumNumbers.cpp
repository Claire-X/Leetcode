//recursion
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return root->val;
        if(root->left) root->left->val += root->val*10;
        if(root->right) root->right->val += root->val*10;
        return sumNumbers(root->left)+sumNumbers(root->right);
    }
};

//iteration
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        
        if(!root) return 0;
        int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            
            if(!n->right && !n->left) sum += n->val;
            
            if(n->left) {
                n->left->val += n->val*10;
                q.push(n->left);
            }
            if(n->right) {
                n->right->val += n->val*10;
                q.push(n->right);
            }
        }
        return sum;
    }
};
