//O(n2)
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int index = INT_MIN, value = INT_MAX;
		int l = -1, r = -1;
		for (int i = num.size() - 1; i > 0; i--)
			for (int j = i - 1; j >= 0; j--) {
				if (num[i] > num[j])
					if (j > index || (j == index && num[i] < value)) {
						l = j;
						r = i;
						index = j;
						value = num[i];
					}
			}
		if (l != -1) {
			swap(num[l], num[r]);
			sort(num.begin() + l + 1, num.end());
			return;
		}

		reverse(num.begin(), num.end());
		return;
	}
};

//O(n)
class Solution {
public:
    void nextPermutation(vector<int> &num) {

        int l=-1,r=-1;
        for(int i =num.size()-1;i>0;i--)
            if(num[i-1]<num[i]){
                l = i-1;
                break;
            }
        for(int j = l+1;j<num.size();j++){
            if(num[j]>num[l])
                r = j;
        }           
        if(l!=-1 && r!=-1) {
            swap(num[l],num[r]);
            sort(num.begin()+l+1,num.end());
            return;
        }

        reverse(num.begin(),num.end());
        return;
    }
};
