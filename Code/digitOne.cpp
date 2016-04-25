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

//Solution 2: 逐位数1，千位1个数 + 百位1个数 + ...
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        int tmp = n;
        vector<int> digits;
        while(tmp){
            digits.push_back(tmp%10);
            tmp/=10;
        }
        int res=0;
        for(int i = digits.size()-1;i>=0;i--){
            res+=i<digits.size()-1?n/(int)pow(10,i+1)*pow(10,i):0;
            if(digits[i]>=1)
                res+= digits[i]>1?pow(10,i):((n%(int)pow(10,i))+1);
        }
        return res;
    }
};
