//O(n)
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int cur =A[0],max_sum=A[0];
        for(int i=1;i<n;i++){
            cur = max(A[i],cur+A[i]);
            max_sum = max(max_sum,cur);
        }
        return max_sum;
    }
};

//Divide and conquer
class Solution {
public:
    int maxSubArray(int A[], int n) {
        return maxSubArray(A,0,n);
    }
private:
    int maxSubArray(int A[], int start, int end){
        if(start >= end) return INT_MIN;
        int mid = (start+end)/2,left = A[mid],right = A[mid];
        int maxLeft=A[mid],maxRight=A[mid];
        for(int i = mid-1;i>=start;i--){
            left += A[i];
            maxLeft = max(maxLeft,left);
        }
        for(int j = mid+1;j<end;j++){
            right += A[j];
            maxRight = max(maxRight,right);
        }
        int max_sum = max(maxSubArray(A,start,mid),maxSubArray(A,mid+1,end));
        max_sum = max(max_sum,maxRight+maxLeft-A[mid]);
        return max_sum;
    }
};
