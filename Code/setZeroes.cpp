//O(m+n) space
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<bool> row(m, false);
		vector<bool> col(n, false);
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) 
				if (matrix[i][j] == 0) 
				    row[i] = col[j] =true;
		
		for(int i =0;i<m;i++)
		    if(row[i])
		        fill_n(matrix[i].begin(),n,0);
		
		for(int j = 0;j<n;j++)
		    if(col[j])
		        for(int i =0;i<m;i++)
		            matrix[i][j]=0;

	}
};

//O(1) space
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		
		bool row1=false;
		bool col1 =false;
		
		for(int i = 0;i<m;i++){
		    if(matrix[i][0]==0) {
		        col1=true;
		        break;
		    }
		}
		
		for(int j = 0;j<n;j++){
		    if(matrix[0][j]==0) {
		        row1=true;
		        break;
		    }
		}
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++) 
				if (matrix[i][j] == 0) 
				    matrix[i][0] = matrix[0][j]=0;
		
		for(int i =1;i<m;i++)
		    if(matrix[i][0]==0)
		        fill_n(matrix[i].begin(),n,0);
		
		for(int j = j;j<n;j++)
		    if(matrix[0][j]==0)
		        for(int i =0;i<m;i++)
		            matrix[i][j]=0;
		
		if(row1) fill(matrix[0].begin(),matrix[0].end(),0);
		if(col1)
		        for(int i =0;i<m;i++)
		            matrix[i][0]=0;

	}
};
//O(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!n) return;
        int m=matrix[0].size();
        if(!m) return;
        vector<bool> zero(m,false);
        for(int i=0;i<n;i++){
            bool flag=false;
            for(int j=0;j<m;j++)
                if(matrix[i][j]==0) {
                    zero[j]=true;
                    flag = true;}
            if(flag) fill_n(&matrix[i][0],m,0);
        }
        for(int j=0;j<matrix[0].size();j++)
            if(zero[j])
                for(int i=0;i<matrix.size();i++)
                    matrix[i][j]=0;
    }
};
