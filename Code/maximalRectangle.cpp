//DP 本行的左边界为 上一行左边界 与 左边最近的0位置 之间的最大值 即max(left,l[j]).同理得到右边界
//以i行为基准h[j]高的直方面积因此为h[j]*(r[j]-l[j])
//2016-4-25 update: 每次计算的是matrix[i][j]位置高度最高的rectangle，而非面积最大的。这样每个rectangle都会被计算到至少一次，并更新maxArea变量
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        
        int result=0;
        vector<int> h(n,0);
        vector<int> l(n,0);
        vector<int> r(n,n);
        
        
        for(int i =0;i<m;i++){
            int right = n,left = 0;
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '1'){
                    h[j]++;
                    l[j] = max(left,l[j]);
                }else{
                    left=j+1;
                    h[j]=0;l[j]=0;r[j]=n;
                }
            }
            
            for(int j = n-1;j>=0;j--){
                if(matrix[i][j] == '1'){
                    r[j] = min(right,r[j]);
                    result = max(result,h[j]*(r[j]-l[j]));
                }else{
                    right=j;
                    h[j]=0;l[j]=0;r[j]=n;
                }
            }
        }
        return result;
    }
};

//利用largest rectangle histogram
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        if(n==0) return 0;
        vector<vector<int> > heights(m,vector<int>(n+1,0));
        for(int j = 0;j<n;j++){
            int start = -1;
            for(int i =0;i<m;i++)
                if(matrix[i][j]=='1') heights[i][j] = i-start;
                else start=i;
        }
        int result=0;
        for(int i= 0;i<m;i++){
            result = max(result,largest(heights[i]));
        }
        return result;
    }

    int largest(vector<int>&height){
        stack<int> stk;
        int n = height.size();
        int result = 0;
        for(int j=0;j<n;j++){
            if(stk.empty()||height[stk.top()]<height[j])
                stk.push(j);
            else{
                int h = stk.top();
                stk.pop();
                result = max(result,height[h]*(stk.empty()?j:j-stk.top()-1));
                j--;
            }
        }
        return result;
    }
};
