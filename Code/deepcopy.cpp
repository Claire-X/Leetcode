class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        unordered_map<RandomListNode*,RandomListNode*> copy;
        RandomListNode dummy(0),*pre = &dummy,*tmp = head;
        while(head){
            RandomListNode* newh = new RandomListNode(head->label);
            pre->next = newh;
            copy[head] = newh;
            head = head->next;
            pre = pre->next;
        }
        pre = dummy.next;
        head = tmp;
        while(head){
            if(head->random)
                pre->random = copy[head->random];
            head = head->next;
            pre = pre->next;
        }
        return dummy.next;
    }
};
