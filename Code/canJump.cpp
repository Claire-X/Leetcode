//Greedy
class Solution {
public:
    bool canJump(int A[], int n) {
         int maxReach=0,local;
         for(int i =0;i<=maxReach;i++){
             local = i+A[i];
             maxReach = max(maxReach,i+A[i]);
             if(maxReach>=n-1) return true;
         }
         return false;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        for(int i=0;i<nums.size()&&i<=reach;i++){
            reach = max(reach,i+nums[i]);  
        }
        return reach>=nums.size()-1;
    }
};

//DP 达到i有两种方法，经过i-1和不经过。对比走楼梯

class Solution {
public:
    bool canJump(int A[], int n) {
        vector<int> f(n);
        f[0] = A[0];
        for(int i = 1;i<n;i++){
            f[i] = max(f[i-1],A[i-1])-1;
            if(f[i]<0) return false;
        }
        return true;
         
    }
};
