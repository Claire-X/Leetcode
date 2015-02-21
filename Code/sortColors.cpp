//counting sort
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

//Dual pointer
class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0, blue=n-1;
        for(int i =0;i<=blue;){
            if(A[i]==0)
                swap(A[i++],A[red++]);
            else if(A[i]==2)
                swap(A[i],A[blue--]);
            else i++;
        }
    }
};

//quick sort
class Solution {
public:
    void sortColors(int A[], int n) {
        int left= 0, right=n-1;
        while(left<right){
            while(A[left] == 0 && left<right) left++;
            while(A[right]!=0 && right>left) right--;
            if(left<right)
            swap(A[left],A[right]);
        }
        right = n-1;
         while(left<right){
            while(A[left] == 1 && left<right) left++;
            while(A[right]==2 && right>left) right--;
            if(left<right)
            swap(A[left],A[right]);
        }
    }
};

//STL partition
class Solution {
public:
    void sortColors(int A[], int n) {
    
        partition(partition(A,A+n,bind1st(less<int>(),1)),A+n,bind1st(equal_to<int>(),1));
    }
};

// implement partition
class Solution {
public:
    void sortColors(int A[], int n) {
        int left= 0,pos=0;
        for(;left<n;left++)
            if(A[left]==0)
                swap(A[pos++],A[left]);
        
        left = pos;
        for(;left<n;left++)
            if(A[left]==1)
                swap(A[pos++],A[left]);
    }
    
};
