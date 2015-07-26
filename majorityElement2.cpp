class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int ma,mb,ca=0,cb=0;
        for(int i:nums){
            if(ca==0 && (cb==0||cb>0 && i!=mb)){
                ma = i;
                ca++;
            }else if(cb==0 && (ca==0||ca>0 && i!=ma)){
                mb=i;
                cb++;
            }
            else if(i==ma)
                ca++;
            else if(i==mb)
                cb++;
            else{
                ca--;
                cb--;
            }
        }
        
        if(ca>0 && count(nums.begin(),nums.end(),ma)>nums.size()/3) res.push_back(ma);
        if(cb>0 &&count(nums.begin(),nums.end(),mb)>nums.size()/3)  res.push_back(mb);
        return res;
        
    }
};
