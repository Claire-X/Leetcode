class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        unordered_map<int,int> counts;
        for_each(num.begin(),num.end(),[&counts](int e){
           if(counts.find(e)!=counts.end())
                counts[e]+=1;
            else counts[e] = 1;
        });
        vector<int> path;
        vector<vector<int> > result;
        int n = num.size();
        dfs(counts,result,path,n);
        return result;
    }
    
    void dfs(unordered_map<int,int> &counts, vector<vector<int> > &result,vector<int> &path,int n){
        if(path.size()==n){
            result.push_back(path);
            return;
        }
        
        for(auto e : counts){
            int count = 0;
            for(auto i:path){
                if(i==e.first)
                    count++;
            }
            if(count<e.second){
                path.push_back(e.first);
                dfs(counts,result,path,n);
                path.pop_back();
            }
        }
    }
       
    
};
