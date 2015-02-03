/*
 * pathSum.cpp
 *
 *  Created on: 2015��1��31��
 *      Author: Claire
 */
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



