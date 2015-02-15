class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int mark, index = 0, i = 0;
		while (i < n) {
			mark = A[i];
			A[index++] = A[i];
			int tmp = i;
			while (i < n && A[i] == mark)
				i++;
			if (i - tmp > 1)
				A[index++] = mark;
		}
		return index;
	}
};
