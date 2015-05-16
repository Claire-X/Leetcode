class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        return inorder(root,in);
    }
    bool inorder(TreeNode* root,vector<int> &in){
        if(!root) return true;
        if(!inorder(root->left,in)) return false;;
        if(in.size())
            if(root->val <= in.back()) return false;
        in.push_back(root->val);
        if(!inorder(root->right,in)) return false;
        return true;
    }
};
