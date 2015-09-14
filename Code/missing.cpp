//xor
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, missing = nums.size();
        for(int n:nums){
            missing^=n;
            missing^=i;
            i++;
        }
        return missing;
    }
};

//swapping numbers to the same index cell
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
            if(i!=nums[i] && nums[i]<n){
                swap(nums[i],nums[nums[i]]);
                i--;
            }
        for(int i=0;i<n;i++)
            if(nums[i]==n) return i;
    }
};
