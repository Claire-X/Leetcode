//BFS Solution: use a graph to represent the string, vertices are the beginging position of words, edges are words. for example
//nightmare can be represented by 0->5->9, thus the problem turns to examine if there exsit a path from 0 to s.size()-1
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<int> visited;
        queue<int> q;
        
        q.push(0);
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            if(visited.find(v)==visited.end()){
                visited.insert(v);
                for(int i =v;i<s.size();i++){
                    string str = s.substr(v,i-v+1);
                    if(dict.find(str)!=dict.end()){
                        q.push(i+1);
                        if(i==s.size()-1) return true;
                    }
                }
                if(visited.size()==s.size()) return false;
            }
        }
        
        return false;
    }
};

//DP solution
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
       int n = s.size();
       vector<bool> f(n+1,false);
       f[0]=true;
       
       for(int i =1;i<=n;i++)
           for(int j =i-1;j>=0;j--){
               if(f[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                f[i]=true;
           }
       return f[n];
    }
};
