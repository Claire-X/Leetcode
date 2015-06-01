class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int md=INT_MAX;
        for(int i =0;i<nums.size();i++){
            if(umap.find(nums[i])!=umap.end()){
               md = min(i-umap[nums[i]],md);
               if(md<=k) return true;
            }
            umap[nums[i]] = i;
        }
        return false;
    }
};
