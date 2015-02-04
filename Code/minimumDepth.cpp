//recursion
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        if(root->left == NULL&&root->right==NULL) return 1;
        else if(root->left==NULL) return minDepth(root->right)+1;
        else if(root->right==NULL) return minDepth(root->left)+1;
        else return min(minDepth(root->left)+1,minDepth(root->right)+1);
    }
};
//iteration
class Solution {
public:
    int minDepth(TreeNode *root) {
    if(root==NULL) return 0;
    queue<pair<TreeNode*,int> > q;
    q.push(make_pair(root,1));
    while(!q.empty()){
        TreeNode* n = q.front().first;
        int depth = q.front().second;
        if(n->left==NULL && n->right==NULL) return depth;
        if(n->left) q.push(make_pair(n->left,depth+1));
        if(n->right) q.push(make_pair(n->right,depth+1));
        q.pop();
    }
    }
};
