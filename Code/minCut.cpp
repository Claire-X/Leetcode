class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n<2) return 0;

        bool f[n][n];
        int c[n];
        fill_n(c,n,INT_MAX);
        c[0]=0;
        
        for(int j = 0;j<n;j++){
            for(int i =j;i>=0;i--){
                if((j-i<2||f[i+1][j-1])&&s[i]==s[j]){
                    f[i][j]=true;
                    if(i==0) c[j]=0;
                    else c[j]=min(c[j],c[i-1]+1);
                }
                else f[i][j] = false;
            }
        }

        return c[n-1];
    }

};
