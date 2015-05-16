//second
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int h = triangle.size();
        if(!h) return 0;
        if(h==1) return triangle[0][0];
        for(int i =1;i<h;i++){
            triangle[i][0]+=triangle[i-1][0];
            for(int j = 1;j<i;j++)
                triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
            triangle[i][i]+=triangle[i-1][i-1];
        }
        return *min_element(triangle[h-1].begin(),triangle[h-1].end());
    }
};

//first
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for(int i = triangle.size()-2;i>=0;i--)
            for(int j=0;j<i+1;j++){
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
            return triangle[0][0];
    }
};
