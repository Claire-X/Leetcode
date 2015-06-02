//second
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]<nums[left]){
                if(target>nums[mid]&&target<=nums[right])
                    left=mid+1;
                else right = mid-1;
            }
            else if(nums[mid]>nums[left]){
                if(target>=nums[left]&&target<nums[mid])
                    right = mid-1;
                else left = mid+1;
            }else left++; //[1,1,3,1] [1,3,1,1,1] 无法分辨target所在区间，因此简单增加left
                        //考虑只剩两个元素的情况只能是left++不能right--
        }
        return false;
    }
};
//first
class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n ==0) return -1;
        int start =0;
        int end = n-1;

        while(start<=end){
            int mid = (start+end)/2;
            if(A[mid]==target) return true;
            if(A[start]<A[mid]){
                if(target<A[mid]&& target>=A[start]) end = mid-1;
                else start = mid+1;
            }else if(A[start]==A[mid]){
                start++;
            }else {
                if(target>A[mid]&& target<=A[end]) start = mid+1;
                else end = mid-1;
            }
        }
        return false;
    }
};
