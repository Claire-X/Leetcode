//
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result=0,i =31;
        for(;i>=0;i--){
            if( ((1<<i)&n) != ((1<<i)&m) ) return 0;
            if((1<<i)&n) break;
        }
        if(i<0) return 0;
       
        for(int j =i;j>=0;j--){
            if( ((1<<j)&n) == ((1<<j)&m) )
                result|=((1<<j)&n);
            else break;
        }
        return result;
    }
};
