//two pointer left and right, only consider the results between them; if h[left]<h[right], move the right pointer won't make the 
//area greater, only possibility is to move left to right
class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0,right = height.size()-1,max_volume = 0;
        while(left<right){
            int cur = (right - left)*min(height[left],height[right]);
            max_volume = max(cur,max_volume);
            if(height[left]<=height[right])
                left++;
            else
                right--;
        }
        return max_volume;
    }
};
