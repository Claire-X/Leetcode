//第二次写借鉴quickSort的方法
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
       if(m+n==1) return m>0?A[0]:B[0];
       bool flag = (m+n)%2;
       int k =(m+n)/2,i=0,j=0,left,right;
       while(i+j<k+1){
           int a = i<m?A[i]:INT_MAX;
           int b = j<n?B[j]:INT_MAX;
           if(a<b) {
               i++;
               if(i+j==k) left=a;
               if(i+j ==k+1) right =a;
           }
           else {
               j++;
               if((i+j)==k) left=b;
               if((i+j)== k+1) right =b;
           }
      }
        return flag? right:(left+right)/2.0;
    }

};

//O(log(m+n))的方法
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
       int k = (m+n)/2;
       return (m+n)%2? findK(A,m,B,n,k+1):(findK(A,m,B,n,k+1)+findK(A,m,B,n,k))/2.0;
    }
    double findK(int A[], int m, int B[], int n,int k){
        if(m>n) return findK(B,n,A,m,k);
        if(m==0) return B[k-1];
        if(k==1) return min(A[0],B[0]);
        int a = k/2>m? m:k/2-1;
        int b = k-a;
        if(B[b-1]<A[a-1]) return findK(A,m,B+b,n-b,k-b);
        if(B[b-1]>A[a-1]) return findK(A+a,m-a,B,n,k-a);
        else return A[a-1];
    }

};

//第一次写，代码过于冗余
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
