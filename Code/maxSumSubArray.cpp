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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0,maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            maxSum = max(cur,maxSum);
            if(cur<0) cur=0;
        }
        return maxSum;
    }
};
//Divide and conquer
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxsub(nums,0,nums.size()-1);
    }
    int maxsub(vector<int>& nums,int start, int end){
        if(start == end) return nums[start];
        int mid = (start+end)/2;
        int lm=0,rm=0,left=0,right=0;
        for(int i=mid-1;i>=start;i--){
            left+=nums[i];
            lm=max(lm,left);
        }
        for(int i=mid+1;i<=end;i++){
            right+=nums[i];
            rm = max(rm,right);
        }
        int m = max(maxsub(nums,start,mid),maxsub(nums,mid+1,end));
        m = max(rm+lm+nums[mid],m);
        return m;
    }
};
