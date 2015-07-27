class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxs = INT_MIN;
        maxPath(root,maxs);
        return maxs;
    }
    
    int maxPath(TreeNode* root, int& maxs){
        if(!root) return 0;
        int left = maxPath(root->left,maxs);
        int right = maxPath(root->right,maxs);
        maxs = max(maxs,left+right+root->val);
        return max(0,max(left,right)+root->val);
    }
};
