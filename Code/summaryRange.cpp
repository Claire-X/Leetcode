class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(!nums.size()) return result;
        int start = nums[0];
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1||nums[i] != nums[i+1]-1){
                string cur;
                if(start!=nums[i]){
                    cur = to_string(start);
                    cur+="->";}
                cur+=to_string(nums[i]);
                result.push_back(cur);
                if(i!=nums.size()-1)
                    start = nums[i+1];
            }
        }
        return result;
    }
};
