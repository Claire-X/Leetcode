class Solution {
public:
    void solve(vector<vector<char>> &board){
        if(board.size()==0)return;
        int w=board[0].size();
        int h = board.size();
        for(int i =0;i<w;i++){
            bfs(board,0,i);
            bfs(board,h-1,i);
        }
        for(int i =0;i<h;i++){
            bfs(board,i,0);
            bfs(board,i,w-1);
        }
        for(int i = 0;i<h;i++)
            for(int j= 0;j<w;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='+') board[i][j]='O';
            }
    }
private:
    void bfs(vector<vector<char>> &board, int x, int y){
        queue<pair<int,int> > q;
        visit(board,q,x,y);
        while(!q.empty()){
        int xn = q.front().first;
        int yn = q.front().second;
        q.pop();
        visit(board,q,xn-1,yn);
        visit(board,q,xn,yn-1);
        visit(board,q,xn+1,yn);
        visit(board,q,xn,yn+1);
        }
    }
    void visit(vector<vector<char>> &board, queue<pair<int,int> > &q,int x, int y){
        int w=board[0].size();
        int h = board.size();
        if(x<0||x>=h||y<0||y>=w||board[x][y]!='O') return;
        board[x][y]='+';
        q.push(make_pair(x,y));
        
    }
};
