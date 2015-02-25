//iteration
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(!root) return result;
        stack<pair<TreeNode*,int> > stk;
        stk.push(make_pair(root,1));
        while(!stk.empty()){
            auto n = stk.top();
            stk.pop();
            if(n.second==1){
                stk.push(make_pair(n.first,0));
                if(n.first->right) stk.push(make_pair(n.first->right,1));
                if(n.first->left) stk.push(make_pair(n.first->left,1));
                
            }
            else result.push_back(n.first->val);
        }
        return result;
    }

};

//recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if(!root) return vector<int>();
        vector<int> result;
        vector<int> left = postorderTraversal(root->left);
        copy(left.begin(),left.end(),back_inserter(result));
        

        vector<int> right = postorderTraversal(root->right);
        copy(right.begin(),right.end(),back_inserter(result));
     
        result.push_back(root->val);
        return result;
    }

};
