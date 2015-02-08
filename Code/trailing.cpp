class Solution {
public:
    int trailingZeroes(int n) {
        int x=5;
        int ans=0;
        while(n>=x){
            ans += n/x;
            x*=5;
        }
        return ans;
    }
};
