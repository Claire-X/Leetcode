class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > tri;
		tri.resize(numRows);
		for (int k = 0; k < numRows; k++)
			tri[k].resize(k + 1);
		if (numRows == 1)
			tri[0][0] = 1;
		if (numRows >= 2) {
			tri[0][0] = 1;
			tri[1][0] = 1;
			tri[1][1] = 1;
			int i = 2;
			while (i < numRows) {
				for (int j = 0; j < i + 1; j++) {
					if (j == 0)
						tri[i][j] = 1;
					else if (j <= (i / 2))
						tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
					else
						tri[i][j] = tri[i][i - j];
				}
				i++;
			}
		}
		return tri;
	}
};
