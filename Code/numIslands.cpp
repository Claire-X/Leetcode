class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {

        if(!grid.size()||!grid[0].size()) return 0;
        int num=1;

        for(int i = 0;i<grid.size();i++)
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]=='1') {
                    num++;
                    visit(grid,i,j,num);
                }
            }
        if(num>=2) return num-1;
        else return 0;

    }
        
        void visit(vector<vector<char>> &grid,int i,int j,int num){
               if(grid[i][j]=='1') grid[i][j] = '1'+num;
               else return;
               if(i>0) visit(grid,i-1,j,num);
               if(j>0) visit(grid,i,j-1,num);
               if(i<grid.size()-1) visit(grid,i+1,j,num);
               if(j<grid[0].size()-1) visit(grid,i,j+1,num);
           }   
};
