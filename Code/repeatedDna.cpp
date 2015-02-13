class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       map<int,int> times;
       int i = 0,l=s.size(),ss=0;
       vector<string> result;
       while(i<l)
       if(times[ss=(ss<<3 | s[i++] & 7) & 0x3fffffff]++ ==1){
           result.push_back(s.substr(i-10,10));
       }
       
      return result; 
    }
};
