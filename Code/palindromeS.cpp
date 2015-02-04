/*
 * palindromeS.cpp
 *
 *  Created on: 2015Äê1ÔÂ31ÈÕ
 *      Author: Claire
 */
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




