//second time
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(n==0) return string("");
        string ss(s);
        reverse(ss.begin(),ss.end());
        for(int i=0;i<n;i++){
            if(s.substr(0,n-i) == ss.substr(i))//find out the longest palindrome in s  
                return ss.substr(0,i)+s;//只能在s前面添加字母，则所找的回文必须开始于s[0];
        }
    }
};
//first
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
