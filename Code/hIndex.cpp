//n
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(),h=0;
        int* radix = new int[n+1]();
        
        for(int c:citations)
            radix[min(c,n)]++;
            
        for(int i=n;i;i--){
            h+=radix[i];
            if(h>=i) return i;
        }
        
    }
};
//binary search nlogn
class Solution {
public:
    int hIndex(vector<int>& citations) {
     sort(citations.begin(),citations.end(),greater<int>());
     int l=0,r=citations.size()-1;
     while(l<=r){
         int mid = l+(r-l)/2;
         if(mid <citations[mid]) l=mid+1;
         else r = mid-1;
     }
     return l;
    }
};
