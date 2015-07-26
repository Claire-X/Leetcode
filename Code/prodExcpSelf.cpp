class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int m=1;
        for(int i:nums){
            res.push_back(m);
            m*=i;
        }
        m =1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i]*=m;
            m*=nums[i];
        }
        return res;
    }
};
