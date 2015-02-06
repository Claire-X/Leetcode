//recursion
lass Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};

//iteration
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if((!p ||!q)) return false;
        queue<TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* p1 = q1.front();
            TreeNode* p2 = q2.front();
            q1.pop();
            q2.pop();
            if(!p1 && !p2) continue;
            if((!p1 ||!p2)) return false;
            if(p1->val != p2->val) return false;
            q1.push(p1->left);
            q1.push(p1->right);
            q2.push(p2->left);
            q2.push(p2->right);
        }
        
        if(!q1.empty()||!q2.empty()) return false;
        return true;
        
    }
};
