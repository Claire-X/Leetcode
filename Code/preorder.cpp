//recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        return pre(root,result);
    }
    vector<int> pre(TreeNode* root, vector<int> & result){
        if(!root) return result;
        result.push_back(root->val);
        pre(root->left,result);
        pre(root->right,result);
        return result;
    }
};

class Solution {
public:
    void preorder(vector<int> &result, TreeNode *root){
        if(!root) return;
        result.push_back(root->val);
        preorder(result,root->left);
        preorder(result,root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(result,root);
        return result;
    }
};
//iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(!root) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *n = stk.top();
            stk.pop();
            result.push_back(n->val);
            if(n->right) stk.push(n->right);
            if(n->left) stk.push(n->left);
        }
        return result;
        
    }
};
