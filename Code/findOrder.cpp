//Kahn
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int> > suc(numCourses);
        
        for(auto p:prerequisites){
            suc[p.second].push_back(p.first);
            indeg[p.first]++;
        }
        
        stack<int> stk;
        vector<int> result;
        
        for(int i=0;i<numCourses;i++){
            if(!indeg[i])
                stk.push(i);
        }
        
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            result.push_back(node);
            for(auto i : suc[node]){
                indeg[i]--;
                if(!indeg[i])
                    stk.push(i);
            }
        }
        if(count_if(indeg.begin(),indeg.end(),bind2nd(greater<int>(),0))) return vector<int>{};
        else return result;        
    }
};

//DFS
class Solution {
public:
bool dfs(vector<vector<int> >& suc,vector<int> &visit,vector<int> &pre, int node,vector<int>& result){
	int n = suc.size();
	visit[node] = 1;
	for(auto i : suc[node]){
		if(visit[i]==1){
			return false;
		} 
		else if(visit[i]==0){
			pre[i]=node;
			if(!dfs(suc,visit,pre,i,result)) 
				return false;
		}
	}
	visit[node]=2;
	result.push_back(node);
	return true;
}

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int> > suc(numCourses);
        
        for(auto p:prerequisites){
            suc[p.second].push_back(p.first);
            indeg[p.first]++;
        }
        
	    vector<int> visit(numCourses,0);
	    vector<int> pre(numCourses,-1);
	    vector<int> result;

	    for(int i =0;i<numCourses;i++){
		    if(!visit[i])
			    if(!dfs(suc,visit,pre,i,result))
			        return vector<int>{};
	    }
	    reverse(result.begin(),result.end());
	    return result;
    }
};
