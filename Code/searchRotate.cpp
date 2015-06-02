//second : mid只可能与left相等 不可能与right 相等

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<nums[left]){
                if(target>nums[mid]&&target<=nums[right])
                    left=mid+1;
                else right = mid-1;
            }
            else{
                if(target>=nums[left]&&target<nums[mid])
                    right = mid-1;
                else left = mid+1;
            }  
            
        }
        return -1;
    }
};

//first
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
//simple solution
/*在每次迭代中，分三种情况：
（1）如果target==A[mid]，那么m就是我们要的结果，直接返回；
（2）如果A[start]<=A[mid]，那么说明从start到mid一定是有序的（没有受到rotate的影响），那么我们只需要判断target是不是在start到mid之间，如果是则把左边缘移到m+1，否则就target在另一半，即把右边缘移到m-1。
（3）如果A[start]>A[mid]，那么说明从mid到end一定是有序的，同样只需要判断target是否在这个范围内，相应的移动边缘即可。*/
class Solution {
public:
    int search(int A[], int n, int target) {
        if (n ==0) return -1;
        int start =0;
        int end = n-1;

        while(start<=end){
            int mid = (start+end)/2;
            if(A[mid]==target) return mid;
            if(A[start]<=A[mid]){
                if(target<A[mid]&& target>=A[start]) end = mid -1;
                else start = mid+1;
            }else{
                if(target>A[mid]&& target<=A[end]) start = mid+1;
                else end = mid-1;
            }
        }
        return -1;
    }
};
