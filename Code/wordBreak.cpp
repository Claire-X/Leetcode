//只要普通深搜加上跳过已知不可分割的case
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n=s.size();
        bool f[n];
        fill_n(f,n,false);
        vector<string> result;
        for(int i=0;i<n;i++)
            for(int j=i;j>=0;j--){
                string str = s.substr(j,i-j+1);
                if(j==0){
                    if(dict.find(str)!=dict.end())
                    	f[i]=true;
                }
                else if(f[j-1]&&dict.find(str)!=dict.end())
                    f[i] = true;
                }
        if(!f[n-1]) return result;
        string cur;
        dfs(s,dict,result,cur,0);
        return result;
    }
    void dfs(string &s,unordered_set<string> &dict,vector<string> &result,string &cur,int start){
        if(start==s.size()){
            result.push_back(cur);
            return;
        }
        for(int i = start;i<s.size();i++){
        	string sub = s.substr(start,i-start+1);
            if(dict.find(sub)!=dict.end()){
                int tmp =cur.size();
                cur+=(cur.size()?" "+sub:sub);
                dfs(s,dict,result,cur,i+1);
                cur=cur.substr(0,tmp);
            }
        }
    }
};

//DP Solution : Output limit exceeded
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n=s.size();
        bool f[n];
        fill_n(f,n,false);
        vector<string> result[n];
        for(int i=0;i<n;i++)
            for(int j=i;j>=0;j--){
                string str = s.substr(j,i-j+1);
                if(j==0){
                    if(dict.find(str)!=dict.end()) {
                    	f[i]=true;
                    	result[i].push_back(str);
                    }
                }
                else if(f[j-1]&&dict.find(str)!=dict.end()){
                    f[i] = true;
                    for(auto it:result[j-1]){
                        string tmp = it+" "+str;
                        result[i].push_back(tmp);
                    }
                }
                }

        return result[n-1];


    }
};
