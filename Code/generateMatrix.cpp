//simplify
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n));
        int first =0,last =n-1;
        int count=1;
        
        while(first<last){
            for(int j = first;j<last;j++)
                matrix[first][j] =count++;
            for(int i = first;i<last;i++)
                matrix[i][last] = count++;
            for(int j = last;j>first;j--)
                matrix[last][j]=count++;
            for(int i = last;i>first;i--)
                matrix[i][first]=count++;
            first++;last--;
        }
        if(first==last) matrix[first][first]=n*n;
        return matrix;
    }
};
