class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int> > two,three,five;
        int count = 1,ugly=1;
        two.push(1);
        three.push(1);
        five.push(1);
        for(;count<n;count++){
            if(two.top()*2 < three.top()*3 && two.top()*2 < five.top()*5){
                ugly = two.top()*2;
                two.pop();
            } else if(three.top()*3<two.top()*2 && three.top()*3 < five.top()*5){
                ugly = three.top()*3;
                three.pop();
            }else{
                ugly = five.top()*5;
                five.pop();
            }
            two.push(ugly);
            three.push(ugly);
            five.push(ugly);
        }
        return ugly;
    }
};
