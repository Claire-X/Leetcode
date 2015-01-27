class Solution {
public:
	string convert(string s, int nRows) {
		if (s.length() < nRows || nRows == 1)
			return s;
		vector<string> zig(nRows);
		int r = 0;
		size_t i = 1;
		zig[0].push_back(s[0]);
		while (1) {
			if (r == 0) {
				r++;
				while (r < nRows) {
					zig[r].push_back(s[i]);
					i++;
					if (i == s.length())
						break;
					r++;
				}
			}
			if (i == s.length())
				break;
			if (r == nRows) {
				r--;
				while (r > 0) {
					r--;
					zig[r].push_back(s[i]);
					i++;

					if (i == s.length())
						break;
				}
			}
			if (i == s.length())
				break;
		}
		string sz = "";
		for (auto c : zig) {
			sz += c;
		}
		return sz;

	}
};
