//My solution is not the simplest; can use two pass, one for not robbing nums[0], which calculates from 1 to n-1;
//the other for not robbing nums[n-1], which calculate from 0 to n-2;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(!n) return 0;
        if(n==2) return max(nums[0],nums[1]);
        int f[n],g[n], ff[n],gg[n];
        //not rob nums[0]
        f[1] = nums[1],g[1] = 0;
        for(int i=2;i<n;i++){
            f[i] = g[i-1]+nums[i];
            g[i] = max(g[i-1],f[i-1]);
        }
        //special case
        if(n==3) return max(max(f[n-1],g[n-1]),nums[0]);
        
        //rob nums[0], which result in that nums[1] and nums[n-1] cannot be robbed
        ff[2] = nums[2],gg[2]=0;
        for(int i=3;i<n-1;i++){
            ff[i] = gg[i-1]+nums[i];
            gg[i] = max(gg[i-1],ff[i-1]);
        }
        return max(max(f[n-1],g[n-1]),max(ff[n-2],gg[n-2])+nums[0]);
    }
};
