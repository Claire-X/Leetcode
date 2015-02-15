//DP 
class Solution {
public:
	int maxProduct(int A[], int n) {
        int max_product=A[0],local_max = A[0],local_min = A[0];
	    for(int i =1;i<n;i++){
	        int a = A[i]*local_max, b = A[i]*local_min;
	        local_max = max(A[i],a);
	        local_max = max(local_max,b);
	        local_min = min(A[i],a);
	        local_min = min(local_min,b);
	        max_product = max(max_product,local_max);
	    }
		return max_product;
	}
};
