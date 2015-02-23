class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<int> path;
        vector<vector<int> > result;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,result,path,0,target);
        return result;
    }
private:
    void dfs(vector<int> &candidates, vector<vector<int> > &result,vector<int> &path,int pos,int gap){
        if(gap == 0) {
             if(find(result.begin(),result.end(),path)==result.end())
                result.push_back(path);
            return;
         }
         
         for(int i = pos;i<candidates.size();i++){
             if(gap<candidates[i]) return;
             path.push_back(candidates[i]);
             dfs(candidates,result,path,i+1,gap-candidates[i]);
             path.pop_back();
         }
        
    }
};
