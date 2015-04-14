/*
 * commonPrefix.cpp
 *
 *  Created on: 2015Äê1ÔÂ31ÈÕ
 *      Author: Claire
 */
 //vertical
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int i =0;
        string result;
        if(!strs.size()) return result;
        while(1){
            char c;
            if(i<strs[0].size()) c= strs[0][i];
            else return result;
            for(auto str:strs)
                if(i>=str.size()||str[i]!=c) return result;
            result+=c;
            i++;
        }
    }
};
 //lateral
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        string com = strs[0];
        for(auto it=strs.begin()+1;it!=strs.end();it++){
            if(com=="") return "";
            if(com.length()>(*it).length()) com=com.substr(0,(*it).length());
            for(int i=0;i<com.length();i++){
                if((*it)[i]!=com[i]){
                    com = com.substr(0,i);
                    break;
                }
            }
        }
        return com;
    }
};



