class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int r=n-1,i=0;
        for(;i<=r;i++){
            if(A[i]==elem){
            while(A[r]==elem && r>i){
                r--;
            }
            if(r>i){
                A[i]=A[r];
                r--;
            }
            else r--;
            
            }
        }
        return r+1;
    }
};
