class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if(n==0) return result;
		generateParenthesis(n, 0, 0, "", result);
		return result;

	}
	void generateParenthesis(int n, int left, int right, string cur,
			vector<string> &result) {
		if (left == n) {
			while (++right <= n) {
				cur += ')';
			}
			result.push_back(cur);
			return;
		}

		if (left == right) {
			generateParenthesis(n, left + 1, right, cur + '(', result);
		}

		if (left > right) {
			generateParenthesis(n, left + 1, right, cur + '(', result);
			generateParenthesis(n, left, right + 1, cur + ')', result);
		}
	}
};
