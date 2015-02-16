//use next_permutation

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size()==0) return result; 
        sort(num.begin(),num.end());
        do{
            result.push_back(num);
        }while(next_permutation(num.begin(),num.end()));
        return result;
    }
};

//recursion
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
       vector<vector<int> > result;
       vector<int> cur;
       dfs(num,cur,result);
       return result;
    }
private:
    void dfs(vector<int> &num,vector<int> &cur, vector<vector<int> > &result){
        if(num.size()==0) return;
        if(cur.size() == num.size()) {
            result.push_back(cur);
            return;
        }
        for(auto digit : num){
            if(find(cur.begin(),cur.end(),digit)==cur.end()){
                cur.push_back(digit);
                dfs(num,cur,result);
                cur.pop_back();
            }
        }
    }
};
