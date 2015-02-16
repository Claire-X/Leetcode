class Solution {
public:
    bool isValidBST(TreeNode *root) {
        vector<int> nodes;
        return inorder(root,nodes);
    }
    bool inorder(TreeNode *root,vector<int> &nodes){
        if(!root) return true;
        if(!inorder(root->left,nodes)) return false;
        nodes.push_back(root->val);
        if(nodes.size()>1)
            if(nodes[nodes.size()-1]<=nodes[nodes.size()-2]) 
                return false;
        if(!inorder(root->right,nodes)) return false;
        return true;
         
    }
};
