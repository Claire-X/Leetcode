//we analyse the problem by binary representation of m and n, if the number of bits of n is greater than m, than bitwise And must
//be 0; secondly, the unequal digits at the tail of m and n result in 0s in the bitwise And. So the problem turns into looking for
//the common parts at the beginning of m and n if their digits are equal.
//simplified
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            n >>= 1;
            m >>= 1;
            ++i;
        }
        return (m << i);
    }
};
//my solution
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
