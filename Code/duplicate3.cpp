class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int,int> m;
        int start = 0;
    	for(int i=0;i<nums.size();i++){
    		if(i-start>k) m.erase(nums[start++]);
    		auto it = m.lower_bound(nums[i]-t);
    		if(it!=m.end() && abs(it->first-nums[i])<=t)
    			return true;
			m[nums[i]]=i;
    	}
    	return false;
    }
};
