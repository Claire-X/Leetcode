//method 1
class Solution {
public:
    int singleNumber(int A[], int n) {
        int digits = sizeof(int)*8;
        int counts[digits];
        fill_n(counts,digits,0);
        for(int i =0;i<n;i++){
            for(int j =0;j<digits;j++){
                counts[j] += A[i]>>j & 1;
                counts[j]%=3;
            }
        }

        int result=0;
        for(int j =0;j<digits;j++){
            result+=(counts[j]<<j);
        }
        return result;
    }
};

//method 2
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0,twos=0,threes;
        for(int i =0;i<n;i++){
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ~(ones&twos);
            ones&=threes;
            twos&=threes;
        }
        return ones;
    }
};

