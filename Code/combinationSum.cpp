//简单dfs
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > result;
        vector<int> cur;
        dfs(candidates,result,cur,target,0);
        return result;

    }
    void dfs(vector<int>& candidates,vector<vector<int> > &result,vector<int> &cur,int target,int i){
        if(target == 0) {
        	result.push_back(cur);
            return;
        }
        if(i>=candidates.size()||target<candidates[i]) return;
        for(int j=i;j<candidates.size();j++){
            if(candidates[j]<=target) {
                cur.push_back(candidates[j]);
                dfs(candidates,result,cur,target-candidates[j],j);
                cur.pop_back();
            }
        }
    }
};
//需要验重 在[2,3,6,7]的例子中，[2,2,3]可能是[2,2]之后直接到[2,2,3] 也可能是[2,2]依然停留在2 然后选择不取 再到了3
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > result;
        vector<int> cur;
        dfs(candidates,result,cur,target,0);
        return result;

    }
    void dfs(vector<int>& candidates,vector<vector<int> > &result,vector<int> &cur,int target,int i){
        if(target == 0) {
        	if(find(result.begin(),result.end(),cur)==result.end())
        		result.push_back(cur);
            return;
        }
        if(i>=candidates.size()||target<candidates[i]) return;
        dfs(candidates,result,cur,target,i+1);
        cur.push_back(candidates[i]);
        target-=candidates[i];
        dfs(candidates,result,cur,target,i);
        dfs(candidates,result,cur,target,i+1);
        cur.pop_back();
    }
};
