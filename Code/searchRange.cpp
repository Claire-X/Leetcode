//STL
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int>result;
        auto endit = upper_bound(A,A+n,target);
        auto beginit = lower_bound(A,A+n,target);
        if(endit!=beginit)
            return vector<int>{beginit-A,endit-A-1};
        else
            return vector<int>{-1,-1};
    }
};

//binary search 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid;
        while(left<=right){
            mid  =  (left+right)/2;
            if(nums[mid]==target)
                break;
            if(nums[mid]<target)
                left=mid+1;
            else right = mid-1;
        }
        if(left>right) return vector<int>{-1,-1};
        int r=mid,l=mid;
        while(nums[r]==target&&r<nums.size()) r++;
        while(nums[l]==target && l>=0) l--;
        return vector<int>{++l,--r};
    }
};

//own implementation of upper/lower
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int end=n-1,begin=0,mid;
        //lower_bound
        while(begin<end){
            mid = (end+begin)/2;
            if(A[mid]>=target) end = mid;
            else begin = mid+1;
        }
        if(A[begin] != target) return vector<int>{-1,-1};
        int tmp=begin;
        //upper_bound
        end=n;
        while(begin<end){
            mid = (end+begin)/2;
            if(A[mid]>target) end = mid;
            else begin = mid+1;
        }

        return vector<int>{tmp,begin-1};
    }
};
