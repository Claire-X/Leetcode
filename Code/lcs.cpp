string lcs(string s,string t){
	int m = s.size(),n = t.size();
	int f[m+1][n+1];//f[i][j]means the lcs of s.substr(0,i+1) and t.substr(0,j+1)
	int p[m][n]; //p marks the move at each position. It is used to backtrack the lcs
	const int ss=1;
	const int tt=2;
	const int st=0;
	for(int i=-1;i<m;i++)
		for(int j=-1;j<n;j++){
			if(i==-1 || j==-1)
				f[i][j]=0;
			else if(s[i]==t[j]){
				f[i][j] = f[i-1][j-1]+1;
				p[i][j]=st;
			}else if(f[i][j-1]>f[i-1][j]){
				f[i][j] = f[i][j-1];
				p[i][j]=ss;
			}else{
				f[i][j] = f[i-1][j];
				p[i][j]=tt;
			}
		}
	int i=m-1,j=n-1,k=f[m-1][n-1];
	string res;
	res.resize(k);
	while(k>0 && i>=0 && j>=0){
		if(p[i][j]==st){
			res[k-1]=s[i];
			i--;j--;k--;
		}else if(p[i][j]==ss){
			j--;
		}else
			i--;
	}
	return res;
}
