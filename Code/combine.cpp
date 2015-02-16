class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> cur;
        dfs(n,k,cur,result);
        return result;
    }
private:
    void dfs(int n, int k,vector<int> &cur,vector<vector<int> > &result){
        if(cur.size()==k){
            result.push_back(cur);
            return;
        }
        for(int i = 1;i<=n;i++){
            if( find(cur.begin(),cur.end(),i) == cur.end()){
                if(cur.size()>0&&cur.back()>i) continue;
                cur.push_back(i);
                dfs(n,k,cur,result);
                cur.pop_back();
            }
        }
    }
};

//iteration
class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;

		vector<bool> select(n, true);
		fill_n(select.begin(), n - k, false);
		vector<int> cur;
		do {
			cur.clear();
			for (int i = 0; i < n && cur.size() < k; i++) {
				if (select[i]) {
					cur.push_back(i + 1);
					if (cur.size() == k)
						result.push_back(cur);
				}
			}
		} while (next_permutation(select.begin(), select.end()));

		return result;
	}
};
