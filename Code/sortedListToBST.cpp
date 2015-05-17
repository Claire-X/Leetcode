//second 24ms
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return convert(head,len(head));
    }
    
    TreeNode* convert(ListNode*head, int l){
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        int ll = l/2;
        ListNode *tmp=head;
        while(--ll)
            head = head->next;

        ListNode *r=head->next;
        head->next = NULL;
        
        TreeNode *root = new TreeNode(r->val);
        root->right = convert(r->next,l-l/2-1);
        root->left = convert(tmp,l/2);
        
        return root;
    }
    
    int len(ListNode* head){
        int l=0;
        while(head){
            l++;
            head=head->next;
        }
        return l;
    }
};

//first
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {

		if (!head)
			return NULL;
		if (head->next == NULL)
			return new TreeNode(head->val);

		ListNode* node = head;
		int i = 1;
		while (node = node->next)
			i++;
		i /= 2;
		node = head;
		while (--i)
			node = node->next;

		ListNode* tmp = node->next;
		node->next = NULL;

		TreeNode* root = new TreeNode(tmp->val);
		root->right = sortedListToBST(tmp->next);
		root->left = sortedListToBST(head);

		return root;

	}
};
