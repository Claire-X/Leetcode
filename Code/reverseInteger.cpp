// Second Solution
class Solution {
public:
    int reverse(int x) {
        bool neg = x<0? true: false;
        long long y = abs((long long)x),r=0;
        
        while(y){
            r=r*10+y%10;
            y/=10;
        }
        
        if(neg) r*=(-1);
        if(r>INT_MAX) return 0;
        if(r<INT_MIN) return 0;
        return (int)r;
    }
};

//first 
class Solution {
public:
    int reverse(int x) {
        bool isNeg = x>>31 ? true:false;
        long long y = abs((long long)x);
        int reverse=0;
        while(y>0){
            int digit = y%10;
            y/=10;
            reverse = reverse*10+digit;
            if((y>0&&reverse>INT_MAX/10)||(reverse==INT_MAX/10&&y%10>7)) return 0;
        }
        return isNeg?-reverse:reverse;
    }
};
