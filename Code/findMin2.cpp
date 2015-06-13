//second
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid,minv=nums[0];
        while(left<=right){
            mid = (right+left)/2;
            minv = min(nums[mid],minv);
            if(nums[mid]<nums[left])
                right = mid;
            else if(nums[mid]>nums[left]){
                 minv = min(minv,nums[left]);
                 left = mid+1;
            }else {
                if(nums[mid]>nums[right]) left++;
                else right--;
            }
        }
        return minv;
    }
};


//first
class Solution {
public:
    int findMin(vector<int> &num) {
        int first=0, last=num.size()-1,minV = num[0];
        while(first<last-1){//这里用first<first<last-1是为了防止[0,0,1]这种mid和first相等且为最小的情况，相应的最后minV也需要和last比较。如果用下面注释中细分情况来解可改为first<last这时最后minV只需和first比较
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
