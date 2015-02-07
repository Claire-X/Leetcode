class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> pre;

		pre.push_back(0);

		int prefix = 1;

		while (n--) {
			for (int i = pre.size() - 1; i >= 0; i--) {
				pre.push_back(pre[i] + prefix);
			}
			prefix *= 2;
		}

		return pre;
	}
};
