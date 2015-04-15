//iteration
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        queue<TreeNode*> l,r;
        r.push(root->right);
        l.push(root->left);
        while(!r.empty() && !l.empty()){
            TreeNode* rn = r.front();
            TreeNode* ln = l.front();
            r.pop();
            l.pop();
            if(!rn&&!ln) continue;
            if(!rn || !ln) return false;
            if(rn->val != ln->val) return false;
            r.push(rn->left);
            r.push(rn->right);
            l.push(ln->right);
            l.push(ln->left);
        }
        
        if(!l.empty()||!r.empty()) return false;
        return true;
    }
};

//recursion
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return isSym(root->left,root->right);
    }
    
    bool isSym(TreeNode *a,TreeNode *b){
        if(!a && !b ) return true;
        if(!a||!b) return false;
  
        return (a->val == b->val) && isSym(a->left,b->right) && isSym(a->right,b->left);
    }
};
