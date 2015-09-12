class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1,right = n;
        if(isBadVersion(1)) return 1;
        while(left<right-1){
            int mid = left+(right-left)/2;
            if(isBadVersion(mid)) right = mid;
            else left = mid;
            }
        return right;
    }
};
