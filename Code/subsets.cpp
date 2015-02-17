class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > result;
		vector<int> cur;
		sort(S.begin(), S.end());
		int n = S.size();
		vector<bool> select(n);

		for (int i = 0; i <= n; i++) {
			fill(select.begin(), select.end(), false);
			fill_n(select.begin(), i, true);
			do {
				for (int j = 0; j < n; j++) {
					if (select[j])
						cur.push_back(S[j]);
				}
				result.push_back(cur);
				cur.clear();
			} while (prev_permutation(select.begin(), select.end()));
		}

		return result;
	}
};
