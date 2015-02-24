class Solution {
public:
    int jump(int A[], int n) {
        if(n==1) return 0;
        int left = 0,right =0,step=0;
        while(left<=right){ //each loop decide the max reach of the ith saut, if the max reach of the ith saut is greater or equal to n-1,return i 
            step++;
            int old_right = right;
            for(int i =left;i<=old_right;i++){
                int new_right = A[i]+i;
                if(new_right>= n-1) return step;
                if(new_right>right) right = new_right;
            }
            left = old_right+1;
        }
    }
};

class Solution {
public:
    int jump(int A[], int n) {
        int last = 0,cur=0,result=0;
        for(int i =0;i<n;i++){
            if(i>last){
                last = cur;
                result++;
            }
            cur = max(cur,A[i]+i);
        }
        return result;
    }
};
