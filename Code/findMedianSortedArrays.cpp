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

//O(log(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n=nums2.size();
        if(m>n) {swap(nums1,nums2);
                swap(m,n);}
        int imin = 0, imax = m,i,j;
        while(imin<=imax){
            i =(imin+imax)/2;
            j=(m+n+1)/2-i;
            if(j>0 && i<m && nums2[j-1]>nums1[i]) imin = i+1;
            else if(i>0 && j<n && nums1[i-1]>nums2[j]) imax=i-1;
            else break;
        }
        int num1,num2;
        if(i==0) num1 = nums2[j-1];
        else if(j==0) num1 = nums1[i-1];
        else num1 = max(nums1[i-1],nums2[j-1]);
        if((m+n)%2) return num1;
        
        if(i>=m) num2 = nums2[j];
        else if(j>=n) num2 = nums1[i];
        else num2 = min(nums1[i],nums2[j]);
        
        return (num1+num2)/2.0;

    }
};
