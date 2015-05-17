//second
class Solution {
public:
    int numTrees(int n) {    
        int f[n+1];
        fill_n(f+2,n-1,0);
        f[0]=f[1]=1;
        
        for(int i = 2;i<=n;i++)
            for(int j=1;j<=i;j++)
                f[i]+=f[j-1]*f[i-j];
        
        return f[n];
    }
};
//first
class Solution {
public:
	int numTrees(int n) {
		if (n >= 0 && n <= 2)
			return n;
		int f[n + 1];
		fill(f + 3, f + n + 1, 0);
		f[0] = 1, f[1] = 1, f[2] = 2;
		for (int i = 3; i <= n; i++)
			for (int j = 0; j < i; j++) {
				f[i] += f[j] * f[i - 1 - j];
			}
		return f[n];
	}
};
