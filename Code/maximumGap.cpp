/*
why the maximum gap could only be some distance between buckets, but not the gap within any bucket.
Given a list of n distinct elements, there would be (n-1) gaps in it. In the worst case where we have the “minimal” maximum gap,
the elements would be evenly distributed, therefore, the maximum gap is (max_element-min_element)/(n-1) which is the length of 
bucket in the above algorithm. In any other case, we would have a larger maximum gap. Therefore, the maximum can only appear as
the distance between certain adjacent buckets, but not the gap within a bucket as it would definitely <= length_of_bucket.
*/
class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        if(n<2) return 0;
        
        int minV=num[0],maxV=num[0];
        
        for(int i = 1; i < n; i++){
            minV = min(minV, num[i]);
            maxV = max(maxV, num[i]);
        }
        
        if(minV == maxV) return 0;
        
        double diff = (maxV-minV)*1.0/(n-1);
        
        int bucket[2*n];
        fill_n(bucket,2*n,0);
        
        for(auto e:num){
            int i =2*(int)((e-minV)/diff);
            bucket[i]=(bucket[i]==0?e:min(bucket[i],e));
            bucket[i+1] = max(bucket[i+1],e);
        }
        int last = bucket[1]; 
        int gap=0;
        for(int i =2;i<2*n;i+=2){
           if(bucket[i]==0) continue;
           gap = max(gap,bucket[i]-last);
           last = bucket[i+1];
        }
        return gap;
    }
};
