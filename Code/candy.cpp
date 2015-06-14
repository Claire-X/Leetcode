//first loop assign values for the uphill, second loop for the down hill, so they won't conflict
//这种两边扫描的方法是一种比较常用的技巧，LeetCode中Trapping Rain Water和这道题都用到了，可以把
//这种方法作为自己思路的一部分，通常是要求的变量跟左右元素有关系的题目会用到哈。
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
