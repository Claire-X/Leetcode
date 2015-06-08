//O(logN*logN)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* ls=root, *rs=root;
        int l=0,r=0;
        while(ls){
            ls = ls->left;
            l++;
        }
        while(rs){
            rs=rs->right;
            r++;
        }
        if(r==l) return pow(2,l)-1;
        return 1+countNodes(root->left)+countNodes(root->right); 
    }
    
};
