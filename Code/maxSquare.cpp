//DP
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        int m =matrix[0].size();
        if(m==0) return 0;
        vector<int> f(m+1,0);
        int maxs=0,pre=0;
        for(int i=0;i<n;i++)
            for(int j=1;j<=m;j++){
                int tmp = f[j];
            	if(matrix[i][j-1]=='0')
            		f[j]=0;
            	else{
                    f[j]=min(min(f[j],f[j-1]),pre)+1;
                    maxs = max(f[j],maxs);
            	}
            	pre = tmp;
            }
        
        return maxs*maxs;
    }
};
