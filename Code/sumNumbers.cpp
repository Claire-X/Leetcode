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
