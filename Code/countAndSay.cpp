class Solution {
public:
	string countAndSay(int n) {
		if (n == 0)
			return "";
		vector<string> say;
		string pre = "1";
		say.push_back(pre);
		for (int i = 1; i < n; i++) {
			int count = 0;
			string current = "";
			for (int j = 0; j < pre.length(); j++) {
				if (j != 0 && pre[j] != pre[j - 1]) {
					current.append(to_string(count) + pre[j - 1]);
					count = 0;
				}
				count++;
				if (j == pre.length() - 1) {
					current.append(to_string(count) + pre[j]);
					count = 0;
				}

			}
			say.push_back(current);
			pre = current;
		}
		return say[n - 1];
	}
};
