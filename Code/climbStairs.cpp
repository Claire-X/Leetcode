class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1) return 1;
        int fn0=1;
        int fn1=1;
        int fn;
        for(int i =1;i<n;i++){
            
            fn=fn0+fn1;
            fn0=fn1;
            fn1=fn;
        }
        return fn;
    }
};
