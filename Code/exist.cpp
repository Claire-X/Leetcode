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
