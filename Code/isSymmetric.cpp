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
