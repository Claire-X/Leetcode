class Solution {
public:
    int titleToNumber(string s) {
      int lm = s.length()-1;
      int total = 0;
      for(auto c:s)
      total += (c-'A'+1)*pow(26.0,double(lm--));
      return total;
    }
};
