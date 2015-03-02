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

// second time write
class Solution {
public:
    int findMin(vector<int> &num) {
        int first=0, last=num.size()-1,minV = INT_MAX;
        while(first!=last){
            int mid = (first+last)/2;
            if(num[first]>num[mid]) last = mid;
            else {
                minV = min(minV,num[first];
                first = mid+1;
            }
        }
        
        minV=min(minV,num[first]);
        return minV;
    }
};
