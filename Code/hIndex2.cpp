class Solution {
public:
    int hIndex(vector<int>& citations) {
     int l=0,n=citations.size(),r=n-1;
     while(l<=r){
         int mid = l+(r-l)/2;
         if(n-mid == citations[mid]) return n-mid;
         else if( n-mid > citations[mid]) l=mid+1;
         else r = mid-1;
     }
     return n-r-1;
    }
};
