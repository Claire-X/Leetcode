//dfs
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s,0,p,0);
    }
    bool isMatch(string &s, int i, string &p, int j){
        if(i==s.size()&&j==p.size()) return true;
        //next char is *
        if(j<p.size()-1 && p[j+1]=='*'){
            if(i<s.size()&&(s[i]==p[j]||p[j]=='.')){
                if(isMatch(s,i+1,p,j)) 
                    return true;
            }
            return isMatch(s,i,p,j+2);
        //next char is not *   
        }else {
            if(i<s.size()&&j<p.size()&&(s[i]==p[j]||p[j]=='.')) return isMatch(s,i+1,p,j+1);
            else return false;
        }
    }
};
//simpler dfs
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s,0,p,0);
    }
    bool isMatch(string &s, int i, string &p, int j){
        if(i>=s.size()&&j>=p.size()) return true;
        if(j>=p.size()) return false;
        if(i==s.size()){
            if(j==p.size()-2&&p.back()=='*') return true;
            else return false;
        }
        if(j<p.size()-1 && p[j+1]=='*'){
            if(s[i]==p[j]||p[j]=='.'){
                if(isMatch(s,i+1,p,j)) 
                    return true;
            }
            return isMatch(s,i,p,j+2);
            
        }else if(s[i]==p[j]||p[j]=='.') return isMatch(s,i+1,p,j+1);
        
        return false;
    }
};
