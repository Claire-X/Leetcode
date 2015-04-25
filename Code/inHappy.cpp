class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> pre;
        while(pre.find(n)==pre.end()){
            pre.insert(n);
            int newn = 0;
            while(n>0){
                int digit = (n%10);
                newn+= (digit*digit);
                n/=10;
            }
            if(newn==1) return true;
            n = newn;
        }
        
        return false;
    }
};
