//second
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool flag;
        for(int i =0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]==word[0] && dfs(board,i,j,0,word))
                        return true;
    }
    
    bool dfs(vector<vector<char>>& board, int i,int j,int step, string word){
        if(step == word.size()) return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
            return false;
        
        if(board[i][j]!=word[step]) return false;
        board[i][j]='*';
        if(dfs(board,i+1,j,step+1,word)||dfs(board,i-1,j,step+1,word)||dfs(board,i,j+1,step+1,word)||dfs(board,i,j-1,step+1,word))
            {   board[i][j]=word[step];
                return true;
            }
        board[i][j]=word[step];
        return false;
    }
};

//first
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        string path("");
        vector<vector<bool> > used(board.size(),vector<bool>(board[0].size(),false));
        bool flag=false;
        for(size_t i =0;i<board.size();i++){
        	for(size_t j = 0;j<board[0].size();j++)
        		if(board[i][j] == word[0]){
        		    flag = dfs(board,word,path,i,j,used);
        		    if(flag) break;
        		}
        	if(flag) break;
        }
        return flag;

    }
    bool dfs(vector<vector<char> > &board, string &word,string &path,int i,int j,vector<vector<bool> > &used){
    	if(i<0|| i>=board.size()||j<0||j>=board[0].size()||used[i][j]) return false;
        path.push_back(board[i][j]);
        used[i][j] = true;
        if(word.substr(0,path.size())!=path) {
            path.pop_back();
            used[i][j] = false;
            return false;
        }else if(word.size()==path.size()) {
        	path.pop_back();
        	used[i][j] = false;
        	return true;
        }

        bool result = dfs(board,word,path,i-1,j,used) || dfs(board,word,path,i,j-1,used)|| dfs(board,word,path,i+1,j,used)||dfs(board,word,path,i,j+1,used);
        path.pop_back();
        used[i][j] = false;
        return result;
    }
};
