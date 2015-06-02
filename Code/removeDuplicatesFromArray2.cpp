//second
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=2,n=nums.size();
        if(n<=2) return n;
        for(int i=2;i<n;i++){
            if(nums[i]==nums[index-2])
                continue;
            nums[index++] = nums[i];
        }
        return index;
    }
};
//first
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int mark,index=0,i=0;
        while(i<n){
            A[index++] = A[i];
            int tmp = i;
            while(i<n && A[i]==A[index-1]) i++;
            if(i-tmp>1){
            	A[index++]=A[i-1];
            }
            	
        }
        return index;
    }
};
