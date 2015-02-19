//DP
class Solution {
public:
    int uniquePaths(int m, int n) {

        int result[m][n];
        fill_n(result[0],n,1);
        for(int i = 1;i<m;i++){
            for(int j =0;j<n;j++){
                if(j==0)
                    result[i][j] = 1;
                else
                    result[i][j] = result[i-1][j]+ result[i][j-1];
            }
        }
        return result[m-1][n-1];
    }

};

// math
class Solution {
public:
    int uniquePaths(int m, int n) {
        return combination(m+n-2,max(m-1,n-1));
	}
	
	long factor(int n,int start=1){
	    long x=1;
	    for(int i =start;i<=n;i++)
	        x*=i;
	    return x;
	}
	
	long combination(int n,int k){
		if(k == 0) return 1;
		if(k==1) return n;
	    long x = factor(n,k+1);
	    x /= factor(n-k);
	    return x;
	}
    
};


//备忘录
class Solution {
public:
    int uniquePaths(int m, int n) {
        this->result = vector<vector<int> >(m+1,vector<int>(n+1,0));
        this->result[1][1] =1;
		return dfs(m,n);
	}
private:
    vector<vector<int> > result;
    int dfs(int m,int n){
        if(m<1 || n<1) return 0;
        if(this->result[m][n]>0) return this->result[m][n];
        else {
            result[m][n] = dfs(m-1,n) + dfs(m,n-1);
            return result[m][n];
        }
    }

};

//Dp with scrollable array
class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[n];
        fill_n(f,n,0);
        f[0] =1;
        for(int i = 0;i<m;i++){
            for(int j =1;j<n;j++){
                f[j] = f[j-1] + f[j];
            }
        }
        return f[n-1];
    }
};

