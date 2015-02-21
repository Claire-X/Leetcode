//make a copy
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        vector<vector<int> > copy(n,vector<int>(n));
        cout<<copy.size();
        for(int i =0;i<n;i++)
            for(int j = 0;j<n;j++)
                copy[j][n-1-i] = matrix[i][j];
        matrix = copy;
    }
};

//in-place_1
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();

        for(int i =0;i<=(n-1)/2;i++){
            rotate(matrix,i,n-2*i);
        }

    }
    void rotate(vector<vector<int> > &matrix,int start,int length){
        if(length <= 1) return;
        int tmp[4];
        int n = matrix.size();
        for(int j = start;j<n-start-1;j++){
            tmp[0] = matrix[start][j];
            tmp[1] = matrix[j][n-start-1];
            tmp[2] = matrix[n-start-1][n-1-j];
            tmp[3] = matrix[n-1-j][start];
            matrix[start][j] = tmp[3];
            matrix[j][n-start-1] = tmp[0];
            matrix[n-start-1][n-1-j] = tmp[1];
            matrix[n-1-j][start] = tmp[2];
        }
    }
};
//in-place_2
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        
        for(int i =0;i<n;i++)
            for(int j=0;j<n-i;j++)
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
        
        for(int i =0;i<n/2;i++)
            for(int j =0;j<n;j++)
                swap(matrix[i][j],matrix[n-1-i][j]);
            
    }
};
