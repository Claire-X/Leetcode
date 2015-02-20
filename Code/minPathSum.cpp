//DP with scrollable array
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int f[n];
        fill(f,f+n,INT_MAX);
        f[0]=0;
        
        for(int i = 0; i<m;i++){
            f[0]+=grid[i][0];
            for(int j =1;j<n;j++){
               f[j] = min(f[j],f[j-1])+grid[i][j];
            }
        }
        return f[n-1];
	}
};
//DP
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();

        int f[m+1][n+1];
        fill_n(f[0],n+1,INT_MAX);
        f[0][1] = 0;
        for(int i =1;i<m+1;i++){
            for(int j =0;j<n+1;j++){
                f[i][j] = (j==0?INT_MAX : grid[i-1][j-1] + min(f[i-1][j],f[i][j-1]));
            }
        }
        return f[m][n];
	}
};
