//recursion
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        if(root->left&&root->right) return min(minDepth(root->left),minDepth(root->right))+1;
        else return max(minDepth(root->left),minDepth(root->right))+1;
    }
};
//iteration
class Solution {
public:
    int minDepth(TreeNode *root) {
    if(root==NULL) return 0;
    queue<TreeNode*> cur,next;
    int level =1;
    cur.push(root);
    while(!cur.empty()){
        TreeNode* n = cur.front();
        if(!n->left && !n->right) return level;
        if(n->left) next.push(n->left);
        if(n->right) next.push(n->right);
        cur.pop();
        if(cur.empty()) {
            level++;
            swap(cur,next);}
    }
    }
};
