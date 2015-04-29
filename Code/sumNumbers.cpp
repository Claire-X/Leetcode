//recursion
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        string cur;
        return dfs(root,cur);;
    }
    
    int dfs(TreeNode *root,string cur){
        if(!root) return 0;
        cur+=root->val+'0';
        int result = 0;
        if(root->left) result+=dfs(root->left,cur);
        if(root->right) result+=dfs(root->right,cur);
        if(!root->right && !root->left)
            for(char c:cur)
                result=result*10+(c-'0');
        return result;
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
