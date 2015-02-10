class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> > result;

		if (num.size() < 3)
			return result;

		for (auto a = num.begin(); *a <= 0 && a < prev(num.end(),2);a=upper_bound(a,prev(num.end(),2),*a)) {
			for (auto b = a + 1; b < prev(num.end());b= upper_bound(b,prev(num.end()),*b)) {

				int target = 0 - *a- *b;
				if (binary_search(b+1,num.end(),target)){
                    result.push_back(vector<int> {*a,*b,target});
				}
			}
		}
		return result;
	}
};
