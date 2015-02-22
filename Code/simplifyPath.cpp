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
