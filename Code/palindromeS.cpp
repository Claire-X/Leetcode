/*
 * palindromeS.cpp
 *
 *  Created on: 2015Äê1ÔÂ31ÈÕ
 *      Author: Claire
 */
//second 
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0,right = s.size()-1;
        while(left<right){
            while(left<right&& !isalnum(s[left])) left++;
            while(left<right&& !isalnum(s[right])) right--;
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};

//first
class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="") return true;
        auto it=s.begin();
        while(it!=s.end()){
            if(((*it)>='A' && (*it)<='Z')||((*it)>='a'&& (*it)<='z')||((*it)>='0'&&(*it)<='9')) it++;
            else{
                s.erase(it);
                continue;
            }
        }
        cout<<s<<endl;
        int r=0;
        int l=s.size()-1;
        while(l>r){
            if(s[l]!=s[r] && abs(s[l]-s[r])!=32) return false;
            l--;
            r++;
        }
        return true;
    }
};




