//second
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root,NULL);
    }
    void connect(TreeLinkNode *root, TreeLinkNode *sibling){
        if(!root) return;
        root->next = sibling;
        connect(root->left,root->right);
        if(sibling)
            connect(root->right,sibling->left);
        else connect(root->right,NULL);
    }
};
//first
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root)
			return;
		connect(root, NULL);

	}
private:
	void connect(TreeLinkNode *node, TreeLinkNode *sibling) {
		node->next = sibling;
		if (node->left) {
			connect(node->left, node->right);
			if (sibling) {
				connect(node->right, sibling->left);
				connect(sibling->left, sibling->right);
			}
		}

	}
};
