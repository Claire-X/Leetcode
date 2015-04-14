//After two month
class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<2 || s.size()<=nRows) return s;
        vector<string> v(nRows);
        bool flag;
        int next = 0;
        for(auto c:s){
            v[next]+=c;
            if(next == nRows-1) flag = false;
            if(next == 0) flag = true;
            if(flag) next++;
            else next--;
        }
        string result;
        for(auto ss:v)
            result+=ss;
        return result;
    }
};

//first solution
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
