class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> len;
        int maxl=0;
        for(int i:nums){
            if(len[i]) continue;
            if(!len[i+1] && !len[i-1]){
                len[i] = 1;
            }
            else if(!len[i+1]){
                len[i] = len[i-len[i-1]] = len[i-1]+1;
            }else if(!len[i-1]){
                len[i] = len[i+len[i+1]] = len[i+1]+1;
            }else
                len[i] = len[i-len[i-1]] = len[i+len[i+1]] = len[i+1]+len[i-1]+1;
            maxl = max(len[i],maxl);
        }
        return maxl;
    }
};
