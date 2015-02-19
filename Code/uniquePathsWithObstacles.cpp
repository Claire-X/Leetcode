class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (!obstacleGrid.size() || obstacleGrid[0][0] == 1)
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int f[n];
		fill_n(f, n, 0);
		f[0] = 1;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				f[j] = (obstacleGrid[i][j] ?  0 : (j==0? f[j]:f[j-1]+f[j]));
		return f[n - 1];
	}
};

//备忘录
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
			return 0;
		this->result = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
		result[1][1] = 1;
		return dfs(obstacleGrid, m, n);
	}
private:
	vector<vector<int> > result;
	int dfs(vector<vector<int> > &obstacleGrid, int m, int n) {
		if (m < 1 || n < 1)
			return 0;
		if (result[m][n] > 0)
			return result[m][n];
		else {
			result[m][n] =
					obstacleGrid[m-1][n-1] ?
							0 :
							dfs(obstacleGrid, m - 1, n)
									+ dfs(obstacleGrid, m, n - 1);
			return result[m][n];
		}
	}
};
