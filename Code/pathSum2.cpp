//second
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if(!root) return result;
        vector<int> path;
        dfs(root,path,result,sum);
        return result;
         
    }
    void dfs(TreeNode *root,vector<int> &path,vector<vector<int>> &result,int sum){
        path.push_back(root->val);
        sum-=root->val;
        if(!root->right&&!root->left){
            if(!sum) result.push_back(path);
            path.pop_back();
            return;
        }
        if(root->left)
            dfs(root->left,path,result,sum);
        
        if(root->right)
            dfs(root->right,path,result,sum);
        
        path.pop_back();
    }
};
//first
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
