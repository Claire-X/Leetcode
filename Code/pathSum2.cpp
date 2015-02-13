class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if(!root) return result;
        vector<int> cur;
        path(root,cur,sum,result);
        return result;
    }
private:
    void path(TreeNode * root,vector<int> cur,int sum,vector<vector<int> >&result){
        if(!root->left && !root->right){
            if(root->val == sum){
                cur.push_back(root->val);
                result.push_back(cur);
            }
        return;
        }
        sum-=root->val;
        cur.push_back(root->val);
        if(root->left) path(root->left,cur,sum,result);
        if(root->right) path(root->right,cur,sum,result);
        
    }
};
