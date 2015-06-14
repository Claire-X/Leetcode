class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> cans(n,1);
        for(int i = 1;i<n;i++)
            if(ratings[i-1]<ratings[i])
                cans[i]=cans[i-1]+1;
            
        for(int i = n-2;i>=0;i--)
            if(ratings[i+1]<ratings[i])
                cans[i]=max(cans[i+1]+1,cans[i]);
                
        return accumulate(cans.begin(),cans.end(),0);
    }
};
