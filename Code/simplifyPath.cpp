//second
class Solution {
public:
    string simplifyPath(string path) {
        if(path.size()==0) return "";
        stack<string> stk;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/') continue;
            int start = i;
            while(i<path.size()&&path[i]!='/') i++;
            string f = path.substr(start,i-start);
            if(f==".."){
                if(!stk.empty())
                    stk.pop();
            } else if(f!=".") stk.push(f);
        }
        if(stk.empty()) return "/";
        string sp;
        while(!stk.empty()){
            string s = stk.top();
            sp.insert(0,s);
            sp.insert(0,1,'/');
            stk.pop();
        }
        return sp;
    }
};
//first
class Solution {
public:
    string simplifyPath(string path) {
        string sub;
        deque<string> q;
        for(size_t i = 1;i<=path.size();i++){
            if(path[i]=='/'||i==path.size()){
                if(sub == ".."){ 
                    if(!q.empty()) 
                        q.pop_back();
                }
                else if(sub.size()!=0 && sub!=".")q.push_back(sub);
                sub.clear();
            }else sub+=path[i];
        }
        string simple;
        if(q.empty()) return"/";

        while(!q.empty()){
            sub = q.front();
            q.pop_front();
            simple+='/'+sub;
        }
        return simple;
    }
};
