//second
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return divide(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* divide(vector<int>& in, int istart,int iend,vector<int>& post,int pstart,int pend){
        if(istart>iend) return NULL;
        TreeNode* root = new TreeNode(post[pend]);
        int i = istart;
        for(;i<=iend;i++)
            if(in[i]==root->val)
                break;
        int ll = i-istart,rl = iend-i;
        if(ll>0) root->left = divide(in,istart,istart+ll-1,post,pstart,pstart+ll-1);
        if(rl>0) root->right = divide(in,i+1,i+rl,post,pend-rl,pend-1);
        return root;
    }
};

//iterator
class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTree(inorder.begin(), inorder.end(), postorder.begin(),
				postorder.end());
	}

private:

	TreeNode *buildTree(vector<int>::iterator ib, vector<int>::iterator ie,
			vector<int>::iterator pb, vector<int>::iterator pe) {
		if (distance(ib, ie) == 0)
			return NULL;

		TreeNode *root = new TreeNode(*(pe - 1));
		if (distance(ib, ie) == 1)
			return root;

		auto i = find(ib, ie, *(pe - 1));
		int leftsize = distance(ib, i), rightsize = distance(ib, ie) - leftsize
				- 1;

		if (leftsize > 0)
			root->left = buildTree(ib, i, pb, pb + leftsize);

		if (rightsize > 0)
			root->right = buildTree(i + 1, ie, pb + leftsize, pe - 1);

		return root;

	}
};


//index
class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	    return buildTree(inorder,0,inorder.size(),postorder,0,postorder.size());
	}
private:
    TreeNode *buildTree(vector<int> &inorder,int ib,int ie, vector<int> &postorder,int pb, int pe) {
       	if (ie == ib)
			return NULL;

		TreeNode *root = new TreeNode(postorder[pe-1]);
		if ((ie - ib) ==1)
			return root;

		auto i = find(inorder.begin()+ib, inorder.begin()+ie, postorder[pe-1]);
		int leftsize = distance(inorder.begin()+ib, i), rightsize=ie-ib-leftsize-1;

		if(leftsize>0)
		    root->left = buildTree(inorder,ib,ib+leftsize,postorder,pb,pb+leftsize);
		
		if(rightsize>0)
		    root->right = buildTree(inorder,ib+leftsize+1,ie, postorder,pb+leftsize,pe-1);
		
		return root;
 
    }
};
