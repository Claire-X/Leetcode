class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()<3) return NULL;
        sort(num.begin(),num.end());
        int gap = INT_MAX;
        int sum;
        for(auto a=num.begin();a<prev(num.end(),2);a = upper_bound(num.begin(),num.end(),*a)){
                auto b = next(a);
                auto c = prev(num.end());
                int x = target - *a;
                while(b<c)
                {   int y = (x - *b -*c);
                    if(abs(y)<gap) {
                        gap = abs(y);
                        sum = target - y;
                    }
                    if(y>0) b = upper_bound(b,c,*b);
                    else c = lower_bound(b,c,*c)-1;
                }
                
            }
        return sum;
    }
};
