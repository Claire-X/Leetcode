class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {

		for (auto v : board)
			for (auto c : v)
				if (c != '.')
					if (count(v.begin(), v.end(), c) > 1)
						return false;

		for (int i = 0; i < 9; i++) {
			string s = "";
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.') {
					if (s.find(board[j][i]) != string::npos)
						return false;
					else
						s += board[j][i];
				}
			}
		}

		for (int i = 0; i < 9; i += 3)
			for (int j = 0; j < 9; j += 3) {
				string s = "";
				for (int m = i; m < i + 3; m++)
					for (int n = j; n < j + 3; n++)
						if (board[m][n] != '.') {
							if (s.find(board[m][n]) != string::npos)
								return false;
							else
								s += board[m][n];
						}
			}

		return true;

	}
};
