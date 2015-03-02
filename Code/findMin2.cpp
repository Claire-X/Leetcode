class Solution {
public:
    int findMin(vector<int> &num) {
        int first=0, last=num.size()-1,minV = num[0];
        while(first<last-1){
            int mid = (first+last)/2;
            
            if(num[first]>num[mid]) last = left(num,mid);
            
            else if(num[first]<num[mid]){
                minV = min(minV,num[first]);
                first = right(num,mid);
            }
            else{
                /*if(num[last]==num[mid]){
                    minV=min(minV,num[first]);
                    first = right(num,first);
                    last =  left(num,last);
                } else if(num[last]<num[mid]) first = right(num,mid);
                else last = left(num,mid);*/
                first++;
            }
        }
        
        if(first<num.size()) minV=min(minV,num[first]);
        if(last>=0) minV=min(minV,num[last]);
        return minV;
    }
    //lower_bound
    int left(vector<int> &num,int index){
        int i = num[index];
        while(num[index] == i ) {
            index--;
            if(index==-1) break;
        }
        return index+1;
    }
    //upper_bound
    int right(vector<int> &num,int index){
        int i = num[index];
        while(num[index] == i ) {
            index++;
            if(index==num.size()) return index;
        }
        return index;
    }
};
