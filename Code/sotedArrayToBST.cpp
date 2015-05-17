//second 20ms
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return convert(num,0,num.size()-1);
    }
    TreeNode* convert(vector<int> &num,int start,int end){
        if(start>end) return NULL;
        if(start==end) return new TreeNode(num[start]);
        int mid = (start+end)/2;
        TreeNode* root=new TreeNode(num[mid]);
        root->right = convert(num,mid+1,end);
        root->left = convert(num,start,mid-1);
        return root;
    }
};

//first 29ms
class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.size() == 0)
			return NULL;
		TreeNode* root = new TreeNode(num[num.size() / 2]);
		if (num.size() == 1)
			return root;
		vector<int> l(num.begin(), num.begin() + num.size() / 2);
		vector<int> r(num.begin() + num.size() / 2 + 1, num.end());
		root->left = sortedArrayToBST(l);
		root->right = sortedArrayToBST(r);
		return root;

	}
};
