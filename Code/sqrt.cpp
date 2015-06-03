class Solution {
public:
    int mySqrt(int x) {
        long long left=0,right=x/2;
        while(left<=right){
            long long mid=(left+right)/2;
            if(mid*mid>x) right = mid-1;
            else if((mid+1)*(mid+1)>x) return mid;
            else left=mid+1;
        }
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int left = 1,right = x/2;
        
        while(left<=right){
            int mid = (left+right)/2;
            if(x/mid > mid) left = mid+1;
            else if(x/mid < mid) right = mid-1;
            else return mid;
        }
        return right;
    }
};
