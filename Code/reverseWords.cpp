class Solution {
public:
	void reverseWords(string &s) {
		int i = s.length() - 1;
		string rs;
		while (i >= 0) {
			while (s[i] == ' ' && i >= 0)
				i--;
			if (i < 0)
				break;
			int start = i;
			while (s[i] != ' ' && i >= 0)
				i--;
			string word = s.substr(i + 1, start - i);
			if (rs != "")
				rs += ' ';
			rs.append(word);
		}
		s = rs;
	}
};
