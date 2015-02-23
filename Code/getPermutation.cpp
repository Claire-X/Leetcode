class Solution {
public:
	string getPermutation(int n, int k) {
		if (n == 1)
			return "1";
		vector<bool> select(n, false);
		string result;
		while (n) {

			int digit = k % factor(n - 1) ? k / factor(n - 1) + 1 : k / factor(n - 1);
			k %= factor(n - 1);
			int count = 0;
			for (int i = 0; i < select.size(); i++) {
				if (!select[i])
					count++;
				if (count == digit) {
					result += (i + 1 + '0');
					select[i] = true;
					break;
				}
			}
			if (k == 0) {
				for (int i = select.size() - 1; i >= 0; i--)
					if (!select[i])
						result += (i + 1 + '0');
				break;
			}
			n--;
		}
		return result;
	}

	int factor(int n) {
		int sum = 1, i = 1;
		while (++i <= n)
			sum *= i;
		return sum;
	}
};
