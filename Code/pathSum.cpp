/*
 * pathSum.cpp
 *
 *  Created on: 2015Äê1ÔÂ31ÈÕ
 *      Author: Claire
 */
 //recursion
 class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        if((root->val==sum) && (!root->left) && (!root->right)) return true;

        
       if(root->left) root->left->val+=root->val;
       if(root->right) root->right->val+=root->val;
       
       return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
       
    }
};
 //second
 class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if((n->val==sum) && (!n->left) && (!n->right)) return true;
            if(n->left) {
                n->left->val+=n->val;
                q.push(n->left);
            }
            if(n->right) {
                n->right->val += n->val;
                q.push(n->right);
            }
        }
        
        return false;
       
    }
};
 
 //first
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
         if(root == NULL) return false;
         stack<TreeNode*> stk;
         stk.push(root);
         while(!stk.empty()){
             TreeNode* pre=stk.top();
             stk.pop();
             if(pre->left==NULL && pre->right==NULL){
                 if(pre->val==sum) return true;
                 else continue;
             }
             int v = pre->val;
             if(pre->left!=NULL) {
                 pre->left->val+=v;
                 stk.push(pre->left);

             }
             if(pre->right!=NULL) {
                 pre->right->val+=v;
                 stk.push(pre->right);
             }

         }
         return false;

    }
};



