class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        size_t i=0;
        int realstart = newInterval.start,realend=newInterval.end;
        for(;i<intervals.size();i++){
            if(intervals[i].end<realstart) result.push_back(intervals[i]);
            else if(realend<intervals[i].start) break;
            else{
                    if(intervals[i].start<=realstart){
                        realstart = intervals[i].start;
                    }
                    if(intervals[i].end>realend)
                        realend = intervals[i].end;
            }
        }
        result.push_back(Interval(realstart,realend));
        copy(intervals.begin()+i,intervals.end(),back_inserter(result));
            
        return result;
    }
};
