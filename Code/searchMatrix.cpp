//second
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m = matrix[0].size();
        for(auto v:matrix)
            if(target>=v[0] && target<=v[m-1]&& binary_search(v.begin(),v.end(),target))
                    return true;
        return false;
            
    }
};
//first
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int left = 0,right = matrix.size()*matrix[0].size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            int i = mid/matrix[0].size();
            int j = mid%matrix[0].size();
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) left = mid+1;
            else right = mid -1;
        }
        return false;
    }
};
