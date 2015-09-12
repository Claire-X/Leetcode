//DP solution
class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n+1,INT_MAX);
        res[0]=0;
        for(int i=0;i<=n;i++){
            for(int j=1;i+j*j<=n;j++){
                res[i+j*j] = min(res[i+j*j],res[i]+1); 
            }
        }
        return res.back();
    }
};
