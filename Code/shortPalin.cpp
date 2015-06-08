class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string tmp(s);
        reverse(tmp.begin(),tmp.end());
        for(int i=0;i<n;i++){
            if(s.substr(0,n-i)==tmp.substr(i))
                return s.replace(0,0,tmp,0,i);
        }
        return s;
    }
};
