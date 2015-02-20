//recursion
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());

		vector<vector<int> > result;
		vector<int> cur;

		dfs(S, result, cur, 0);

		return result;
	}

	void dfs(vector<int> &S, vector<vector<int> > &result, vector<int> &cur,
			size_t step) {
		if (step == S.size() + 1)
			return;
		if (find(result.begin(), result.end(), cur) == result.end())
			result.push_back(cur);
		dfs(S, result, cur, step + 1);
		cur.push_back(S[step]);
		dfs(S, result, cur, step + 1);
		cur.pop_back();
	}

};
//iteration
//incremental construction
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        int n = S.size();
        int size,pre_size=0;
       
        vector<vector<int> > result(1);
        
        for(int i =0;i<n;i++){
            size = result.size();
            for(int j =0;j<size;j++){
                if(i==0||S[i]!=S[i-1]||j>=pre_size){
                    result.push_back(result[j]);
                    result.back().push_back(S[i]);
                }
            }
            pre_size = size;
        }
       
        return result;
    }
};

//binary 
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        int n = S.size();
        set<vector<int> > result;
        vector<int> cur;
        for(int i = 1<<n;i>0;i--){
            for(int j =0;j<n;j++){
                if(1<<j & i) cur.push_back(S[j]);
            }
            result.insert(cur);
            cur.clear();
        }
        vector<vector<int> > vec;
        copy(result.begin(),result.end(),back_inserter(vec));
        return vec;
    }
};

// bit vector
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        int n = S.size();
        vector<bool> select(n);
        vector<vector<int> > result;
        vector<int> cur;
        for(int i =0;i<=n;i++){
            fill_n(select.begin(),n,false);
            fill_n(select.begin(),i,true);
            do{
                for(int j = 0;j<n;j++){
                    if(select[j]) cur.push_back(S[j]);
                }
                if(find(result.begin(),result.end(),cur)==result.end())
                    result.push_back(cur);
                cur.clear();
            }while(prev_permutation(select.begin(),select.end()));
        }
        return result;
    }
};
