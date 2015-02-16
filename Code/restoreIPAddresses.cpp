class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.length() < 4)
			return result;
		string cur("");
		dfs(s, cur, 0, 1, result);
		return result;
	}
private:
	void dfs(string& s, string& cur, int pre, int end, vector<string> &result) {
		if (end - pre > 3)
			return;
		if (count_if(cur.begin(), cur.end(), bind1st(equal_to<char>(), '.'))
				== 4)
			return;
		if (end == s.length()) {
			if (stoi(s.substr(pre, end - pre)) <= 255
					&& count_if(cur.begin(), cur.end(),
							bind1st(equal_to<char>(), '.')) == 3
					&& (end - pre == 1
							|| (end - pre > 1
									&& s.substr(pre, end - pre)[0] != '0'))) {
				string tmp = s.substr(pre, end - pre);
				cur += tmp;
				result.push_back(cur);
				cur.erase(cur.size() - tmp.size(), tmp.size());
				return;
			} else
				return;
		}
		dfs(s, cur, pre, end + 1, result);
		if (stoi(s.substr(pre, end - pre)) <= 255
				&& (end - pre == 1
						|| (end - pre > 1 && s.substr(pre, end - pre)[0] != '0'))) {
			string tmp = s.substr(pre, end - pre) + '.';
			cur += tmp;
			dfs(s, cur, end, end + 1, result);
			cur.erase(cur.size() - tmp.size(), tmp.size());
		}
	}
};
