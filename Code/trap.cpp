//the volume of water in a certian position depends on the maximum height at the left and at the left
class Solution {
public:
    int trap(vector<int>& height) {
        int max_left=0,max_right=0,l=0,r=height.size()-1,water=0;
        while(l<=r){
            if(max_left<max_right){
                if(height[l]<max_left) water+=max_left-height[l];
                else max_left=height[l];
                l++;
            }else{
                if(height[r]<max_right) water+=max_right-height[r];
                else max_right=height[r];
                r--;
            }
        }
        return water;
    }
};
/遍历数组，用一个栈来维护递减序列，一旦一个元素大于其左元素，则形成坑，那么把这个坑填平，再接着遍历。
class Solution {
public:
    int trap(int A[], int n) {
    stack<int> stk;
    stk.push(0);
    int water=0,bot =0;
    for(int i =1;i<n;i++){
        if(A[i]<=A[stk.top()]) {stk.push(i);bot=A[stk.top()];continue;}
        while(!stk.empty()){
            int left = A[stk.top()];
            water+=(min(A[i],left)-bot)*(i-stk.top()-1);
            bot = min(left,A[i]);
            if(A[i]<left) break;
            else stk.pop();
        }
        stk.push(i);
    }
    return water;
        
    }
};
