class mycomp{
    public:
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(-1);
        ListNode*pre = &dummy;
        priority_queue<ListNode*,vector<ListNode*>,mycomp> pq;
        for(auto n:lists){
            if(n)// this loop takes O(kLogk) since this is building heap
                pq.push(n);
        }
        while(!pq.empty()){
            pre->next = pq.top();
            pq.pop();
            pre = pre->next;
            if(pre->next)
            pq.push(pre->next);
            //pre->next = NULL;
        }
        return dummy.next;
    }
}; 
