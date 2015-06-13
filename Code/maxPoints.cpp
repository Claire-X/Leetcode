class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()==0) return 0;
        unordered_map<double,int> slopes;
        int maxp = 1,local,vertical,dupli;
        for(int i=0;i<points.size();i++){
            vertical = 0;
            local = 0;
            dupli = 1;
            slopes.clear();
            for(int j=i+1;j<points.size();j++){
                if(points[j].x == points[i].x) {
                    if(points[j].y == points[i].y)
                        dupli++;
                    else vertical++;
                    continue;
                }
                double s = (points[i].y-points[j].y)*1.0/(points[i].x-points[j].x);
                slopes[s]++;
                local = max(local,slopes[s]);
            }
            maxp = max(maxp,max(local,vertical)+dupli);
        }
        return maxp;
    }
};
