//second
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
       return generate(n,1); 
    }
    vector<TreeNode*> generate(int n, int start){
        if(n==0) return vector<TreeNode*>{nullptr};
        if(n==1) return vector<TreeNode*>{new TreeNode(start)};
        vector<TreeNode*> result;
        for(int i=1;i<=n;i++){
            vector<TreeNode*> left = generate(i-1,start);
            vector<TreeNode*> right = generate(n-i,start+i);
            for(auto l:left)
                for(auto r:right){
                    TreeNode* root = new TreeNode(start+i-1);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
        }
        return result;
            
    }
};
//first
class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		return generateTrees(0, n);
	}
private:
	vector<TreeNode *> generateTrees(int start, int n) {

		if (n == 0)
			return vector<TreeNode*> { nullptr };
		if (n == 1)
			return vector<TreeNode*> { new TreeNode(start + 1) };
		vector<TreeNode*> result;

		for (int i = 0; i < n; i++) {

			vector<TreeNode *> lefts = generateTrees(start, i);
			vector<TreeNode *> rights = generateTrees(i + 1+start, n-i-1);

			for (auto left : lefts)
				for (auto right : rights) {
					TreeNode *root = new TreeNode(i + 1 + start);
					root->left = left;
					root->right = right;
					result.push_back(root);
				}
		}
		return result;

	}
};
