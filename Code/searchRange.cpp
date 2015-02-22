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
    vector<int> searchRange(int A[], int n, int target) {
        int end=n-1,begin=0,mid;
        while(end>=begin){
            mid = (end+begin)/2;
            if(A[mid] == target) break;
            else if(A[mid]>target) end = mid-1;
            else begin = mid+1;
        }
        if(A[mid] != target) return vector<int>{-1,-1};

        end = begin = mid;
        while(A[end] == target){
            end++;
            if(end == n) break;
        }
        while(A[begin] == target) {
            begin--;
            if(begin==-1) break;
        }
        return vector<int>{begin+1,end-1};
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
