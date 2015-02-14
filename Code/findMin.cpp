class Solution {
public:
	int findMin(vector<int> &num) {
		int start = 0, end = num.size() - 1, mid;

		while (start < end) {
			mid = (start + end) / 2;

			if (num[start] > num[mid]) {
				end = mid;
				continue;
			} else if (num[mid] <= num[end])
				return num[start];
			else {
				start = mid + 1;
				continue;
			}

		}

		return num[start];

	}
};
