class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if (m == 0 && n == 0)
			return NULL;
		bool flag = (m + n) % 2 == 0 ? false : true;
		int mid = (m + n) % 2 == 0 ? (m + n) / 2 : (m + n) / 2 + 1;

		int i = 0, j = 0;
		while (i < m && j < n) {
			if (A[i] <= B[j]) {
				i++;
				if (i + j == mid) {
					if (flag)
						return A[i - 1];
					else {
						if (i < m)
							return (A[i - 1] + (A[i] <= B[j] ? A[i] : B[j]))
									/ 2.0;
						else
							return (A[i - 1] + B[j]) / 2.0;
					}
				}
			} else {
				j++;
				if (i + j == mid) {
					if (flag)
						return B[j - 1];
					else {
						if (j < n)
							return (B[j - 1] + (B[j] <= A[i] ? B[j] : A[i]))
									/ 2.0;
						else
							return (B[j - 1] + A[i]) / 2.0;
					}
				}
			}
		}

		if (i < m && j == n) {
			if (flag)
				return A[mid - j - 1];
			else
				return (A[mid - j - 1] + A[mid - j]) / 2.0;
		}
		if (i == m && j < n) {
			if (flag)
				return B[mid - i - 1];
			else
				return (B[mid - i - 1] + B[mid - i]) / 2.0;
		}
	}
};
