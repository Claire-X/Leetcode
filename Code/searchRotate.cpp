class Solution {
public:
    int search(int A[], int n, int target) {
        if (n ==0) return -1;
        int start =0;
        int end = n-1;

        while(start<end){
            int mid = (start+end)/2;
            if(A[start]>A[mid]){
                end = mid;
            }else{
                if(A[mid]<=A[end]) break;
                else start = mid+1;
            }
        }
        int pivot = start;
        end = (start-1+n)%n;
        while((start-pivot+n)%n < (end-pivot+n)%n){
            int mid = (((start-pivot+n)%n+(end-pivot+n)%n)/2+pivot)%n;
            if(A[mid] == target) return mid;
            else if(A[mid]<target)
                start = (mid+1)%n;
            else end = mid;
        }
        if(A[start] == target) return start;
        return -1;
    }
};
