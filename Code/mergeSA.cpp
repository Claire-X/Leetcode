class Solution {
public:
	void merge(int A[], int m, int B[], int n) {

		int* C = new int[m + n];
		int i = 0;
		int j = 0;
		int k = 0;
		if (m > 0 && n > 0) {
			while (i < m && j < n) {
				if (A[i] <= B[j]) {
					C[k] = A[i];
					i++;
				} else {
					C[k] = B[j];
					j++;
				}
				k++;
			}

		}

		if (j < n) {
			for (; j < n; j++) {
				C[k] = B[j];
				k++;
			}
		}

		if (i < m) {
			for (; i < m; i++) {
				C[k] = A[i];
				k++;
			}
		}

		for (int s = 0; s < m + n; s++)
			A[s] = C[s];
		delete[] C;

	}
};
