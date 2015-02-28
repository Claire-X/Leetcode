//O(n) 与longest valid parenthesis思路类似 已出栈元素已经处理过（满足某条件或某种量度上优于内元素）因此处理新出栈元素可以算上他们
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> stk;
        int maxArea=0;
        for(int i =0;i<height.size();i++){
            if(stk.empty()||height[i]>height[stk.top()])
                stk.push(i);
            else{
                int h = stk.top();
                stk.pop();
                maxArea=max(maxArea,height[h]*(stk.empty()?i:i-stk.top()-1));
                i--;
            }
        }
        return maxArea;
    }
};

//brute force + prune
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        for(int i =0;i<height.size();i++){
            if(i!=height.size()-1&&height[i]<=height[i+1]) continue;
            int minh = INT_MAX;
            for(int j = i;j>=0;j--){
            	minh =  min(minh,height[j]);
                int area = minh*(i-j+1);
                maxArea = max(maxArea,area);
            }
        }
        return maxArea;
    }
};
