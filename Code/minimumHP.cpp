//second
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m=dungeon[0].size();
        int f[n+1][m+1];
        for(int i=n;i>=0;i--)
            for(int j=m;j>=0;j--){
                if(i==n||j==m) f[i][j]=INT_MAX;
                else if(i==n-1&&j==m-1) f[i][j]=dungeon[n-1][m-1]>=0?1:-dungeon[n-1][m-1]+1;
                else {
                    f[i][j] = min(f[i+1][j],f[i][j+1])-dungeon[i][j];
                    if(f[i][j]<1) f[i][j]=1;
                }
            }
        return f[0][0];
    }
};

//刚开始一直想解决由K走到P所遭遇的最小血量，但实际上应该考虑从一个格子走到P所需要最少血量，用倒置的动态规划，即在任意格子，
//可以通过go down走到P 也可通过go right，比较这两条路所需血量，选择对血量损害较小的那个，（数值上较大）
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m =dungeon.size();
        if(m==0) return 0;
        int n = dungeon[0].size();
        if(n==0) return 0;
        int f[n];
        
        f[n-1] = dungeon[m-1][n-1]>0?0:dungeon[m-1][n-1];
        if(f[n-1]>0) f[n-1]=0;
        for(int j =n-2;j>=0;j--){
            f[j] = f[j+1]+dungeon[m-1][j];
            if(f[j]>0) f[j]=0;
        }
        
        for(int i=m-2;i>=0;i--){
            f[n-1] = f[n-1]+dungeon[i][n-1];
            if(f[n-1]>0) f[n-1]=0;
            for(int j=n-2;j>=0;j--){
                f[j]=max(f[j+1],f[j])+dungeon[i][j];
                if(f[j]>0) f[j]=0;
            }
        }
        
        return -f[0]+1;
    }
};
