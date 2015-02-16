class Solution {
public:
	int numTrees(int n) {
		if (n >= 0 && n <= 2)
			return n;
		int f[n + 1];
		fill(f + 3, f + n + 1, 0);
		f[0] = 1, f[1] = 1, f[2] = 2;
		for (int i = 3; i <= n; i++)
			for (int j = 0; j < i; j++) {
				f[i] += f[j] * f[i - 1 - j];
			}
		return f[n];
	}
};
