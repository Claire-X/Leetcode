class Solution {
public:
    void sortColors(int A[], int n) {
        int zeros=0,ones=0,twos=0;
        for(int i =0;i<n;i++){
            if(A[i]==0) zeros++;
            else if(A[i]==1) ones++;
            else twos++;
        }
        for(int i =0;i<n;i++){
            if(i<zeros)A[i]=0;
            else if(i<zeros+ones)
                A[i]=1;
            else A[i] =2;
        }
    }
};
