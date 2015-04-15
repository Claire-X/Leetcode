//Dfs
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        dfs(result,root,0);
        return result;
    }
    
    void dfs(vector<vector<int> > &v,TreeNode *root,int level){
        if(!root) return;
        if(level>=v.size()) v.push_back(vector<int>{root->val});
        else v[level].push_back(root->val);
        dfs(v,root->left,level+1);
        dfs(v,root->right,level+1);
    }
};
