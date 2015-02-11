class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size()<4) return result;
        sort(num.begin(),num.end());
        
        map<int,vector<pair<int,int> > > cache;
        
        for(auto a = num.begin();a<prev(num.end()); a = upper_bound(a,prev(num.end()),*a))
        for(auto b = next(a);b<num.end(); b = upper_bound(b,num.end(),*b)){
            cache[*a+*b].push_back(make_pair(*a,*b));
        }

        for(auto a = num.begin();a<prev(num.end(),3); a = upper_bound(a,prev(num.end(),3),*a))
        for(auto b = next(a);b<prev(num.end(),2); b = upper_bound(b,prev(num.end(),2),*b)){

            int x = target - *a - *b;
            if(cache.find(x) != cache.end()) {
                for(auto it : cache[x]){
                if(*b>it.first) continue;

                result.push_back(vector<int> {*a,*b,it.first,it.second});

                }
            }

        }
        return result;
    }
};
