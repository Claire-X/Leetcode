class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
         stack<pair<TreeNode*,int>> stk;
         stk.push({root,0});
         while(!stk.empty()){
             TreeNode* n = stk.top().first;
             if(stk.top().second){
                k--;
                if(k==0) return n->val;
                stk.pop();
                if(n->right)
                    stk.push({n->right,0});
             }else{
                stk.top().second++;
                if(n->left)
                    stk.push({n->left,0});
             }
         }
    }
};
