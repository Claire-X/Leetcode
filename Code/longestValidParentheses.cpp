class Solution {
public:
    int longestValidParentheses(string s) {
        int maxMatch=0,start = -1;
        stack<int> stk;
        for(int i =0;i<s.size();i++){
            if(s[i]=='(') {stk.push(i);continue;}
            if(!stk.empty()){
                stk.pop();
                if(stk.empty())
                    maxMatch = max(i-start,maxMatch);
                else maxMatch = max(i-stk.top(),maxMatch);
            }else{
                start = i;
            }
            
        }
        return maxMatch;
        
    }
};
