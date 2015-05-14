//Kahn algo for topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int> > suc(numCourses);
        
        for(auto p:prerequisites){
            suc[p.first].push_back(p.second);
            indeg[p.second]++;
        }
        
        stack<int> stk;
        
        for(int i=0;i<numCourses;i++){
            if(!indeg[i])
                stk.push(i);
        }
        
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            for(auto i : suc[node]){
                indeg[i]--;
                if(!indeg[i])
                    stk.push(i);
            }
        }
        
        return !count_if(indeg.begin(),indeg.end(),bind2nd(greater<int>(),0));
    }
};

//DFS for topological sort
class Solution {
public:
bool dfs(vector<vector<int> >& suc,vector<int> &visit,vector<int> &pre, int node){
	int n = suc.size();
	visit[node] = 1;
	for(auto i : suc[node]){
		if(visit[i]==1){
			return false;
		} 
		else if(visit[i]==0){
			pre[i]=node;
			if(!dfs(suc,visit,pre,i)) 
				return false;
		}
	}
	visit[node]=2;
	return true;
}

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int> > suc(numCourses);
        
        for(auto p:prerequisites){
            suc[p.first].push_back(p.second);
            indeg[p.second]++;
        }
        
	    vector<int> visit(numCourses,0);
	    vector<int> pre(numCourses,-1);

	    for(int i =0;i<numCourses;i++){
		    if(!visit[i])
			    if(!dfs(suc,visit,pre,i))
			        return false;
	    }
	    
	    return true;
    }
};
