class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int start = 0;
        int end = num.size()-1;
        int mid;
        while(start<end){
            mid = (start + end)/2;
            if(num[mid]<num[mid+1]) start=mid+1;
            else if(num[mid]<num[mid-1]) end = mid-1;
            else return mid;
        }
         return start;
    }

};
