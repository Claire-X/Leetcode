class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = false;
        for(auto it=digits.rbegin();it!=digits.rend();it++) {
            if((*it)==9) {
                carry=true;
                (*it)=0;
            }
            else {
                (*it)++;
                carry=false;
            }
            if(!carry) break;
        }
        if(carry) digits.insert(digits.begin(),1);
        return digits;
    }
};
