//similar to remove duplicates
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (!n) return 0;
        int index = 0;
        for(int i =0;i<n;i++){
            if(A[i]!=elem) A[index++] = A[i];
        }
        return index;
    }
};
//second
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (!n) return 0;
        int i=0,index = n-1;
        while(i<=index){
            if(A[i]==elem){
                if(i==index) break;
                swap(A[i],A[index--]);
            }else i++;
        }
        return i;
    }
};
//first
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
