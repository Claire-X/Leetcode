class Solution {
public:
    long long countDigitOne(int n) {
        long long d = 1;
        int total=0;
        while(d<=n){
            int a = n/d,b=n%d;
            int digit = a%10;a/=10;
            total += a*d;
            if(digit>1) total+=d;
            else if(digit==1) total+=(b+1);
            d*=10;
        }
        return total;
    }
};
