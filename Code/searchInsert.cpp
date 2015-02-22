//upper_bound
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin = 0;
        int end = n;
        while(end>begin){
            int mid = (end+begin)/2;
            if(A[mid] == target) return mid;
            else if(A[mid]<=target) begin = mid+1;
            else end = mid;
        }
        return begin;
    }
};

//lower_bound
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return distance(A,lower_bound(A,A+n,target));
    }
private:
    template<typename ForwardIterator,typename T>
    ForwardIterator lower_bound(ForwardIterator begin,ForwardIterator end,T target){
        while(begin!=end){
            ForwardIterator mid = next(begin,(end-begin)/2);
            if(*mid<target) begin = ++mid;
            else end = mid;
        }
        return begin;
    }
};
