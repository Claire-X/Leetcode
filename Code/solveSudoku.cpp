//solution 1
//这道题的方法就是用在N-Queens中介绍的常见套路。简单地说思路就是循环处理子问题，对于每个格子，带入不同的9个数，然后判合法，
//如果成立就递归继续，结束后把数字设回空。以上方法是一个非常典型的套路，大部分NP问题的都是可以这个方法，比如N-Queens，
//Combination Sum，Combinations，Permutations等。
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board,0,0);
    }
    
private:
    bool solve(vector<vector<char> > &board,int x,int y){
        if(x==9) return true;
        if(y==9) return solve(board,x+1,0);
        if(board[x][y]=='.'){
            for(int k =1;k<=9;k++){
                board[x][y]=k+'0';
                if(isValid(board,x,y)){
                    if(solve(board,x,y+1))
                        return true;
                }
                board[x][y]='.';
            }
            return false;   
        }else return solve(board,x,y+1);
    }
    bool isValid(vector<vector<char> > &board,int x,int y){
        for(size_t j =0;j<9;j++)
            if(j!=y&&board[x][j]==board[x][y]) return false;
        
        for(size_t i =0;i<9;i++)
            if(i!=x&&board[i][y]==board[x][y]) return false;
        
        for(size_t i=(x/3)*3;i<(x/3)*3+3;i++)
            for(size_t j =(y/3)*3;j<(y/3)*3+3;j++)
                if((i!=x&&j!=y)&&board[i][j]==board[x][y]) return false;
        return true;
    }
};
//solution2 比1慢
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char> > &board){
        for(int i =0;i<9;i++)
            for(int j =0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k =1;k<=9;k++){
                        board[i][j]=k+'0';
                        if(isValid(board,i,j)&&solve(board))
                            return true;
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        return true;
    }
    bool isValid(vector<vector<char> > &board,int x,int y){
        for(size_t j =0;j<9;j++)
            if(j!=y&&board[x][j]==board[x][y]) return false;
        
        for(size_t i =0;i<9;i++)
            if(i!=x&&board[i][y]==board[x][y]) return false;
        
        for(size_t i=(x/3)*3;i<(x/3)*3+3;i++)
            for(size_t j =(y/3)*3;j<(y/3)*3+3;j++)
                if((i!=x&&j!=y)&&board[i][j]==board[x][y]) return false;
        return true;
    }
};
