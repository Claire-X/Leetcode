#include<vector>

class Solution {
public:
    bool isValid(string s) {
        vector<char> parens;
        bool flag = true;
        char pre;
        for(string::iterator it=s.begin();it!=s.end() ;it++){
            if(*it == '{' || *it == '(' || *it == '[')
            parens.push_back(*it);
            else if(*it == '}') {
            	if(parens.empty()) return false;
                pre = parens.back();
                if (pre != '{') return false;
                parens.pop_back();
            }
            else if(*it == ')'){
            	if(parens.empty()) return false;
                pre = parens.back();
                if (pre != '(') return false;
                parens.pop_back();
            }
            else if(*it == ']'){
            	if(parens.empty()) return false;
                pre = parens.back();
                if (pre != '[') return false;
                parens.pop_back();
            }
        }
        if(!parens.empty()) flag = false;
        return flag;
    }
};
