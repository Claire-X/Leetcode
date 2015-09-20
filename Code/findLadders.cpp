 //Used vector<string> for cur/next in my original answer, but output limit exceeded, guess unordered_set is smaller in matter of space
  class Solution {
      public:
          vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
              unordered_set<string> cur,next;
              vector<vector<string>> res;

              unordered_map<string,vector<string> > tree;

              cur.insert(beginWord);
              int l=beginWord.length();
              bool flag = false;

              wordList.insert(endWord);
              while(cur.size() && !flag){
                  for(string w:cur){
                  	string s = w;
                      for(int i =0;i<l;i++)
                          for(char c ='a';c<='z';c++){
                              if(c == s[i]) continue;
                              swap(c,s[i]);
                              if (s == endWord||wordList.find(s)!=wordList.end()){
                                  tree[s].push_back(w);
                                  next.insert(s);
                                  if(s==endWord) flag = true;
                                 }
                              swap(c,s[i]);
                          }
                  }
                  cur.clear();
                  swap(cur,next);
                  for(string s:cur) wordList.erase(s);
             }
             vector<string> path;
             if(flag) buildPath(endWord,beginWord,tree,path,res);

              return res;
          }

          void buildPath(string &bs, string &es, unordered_map<string,vector<string> > &tree, vector<string> &path, vector<vector<string>> &res){
        	        path.push_back(bs);
        	        cout<<bs<<"   ";
                    if(bs==es){
                        res.push_back(path);
                        reverse(res.back().begin(),res.back().end());
                    }else for(string s: tree[bs])
                        buildPath(s,es,tree,path,res);
                    path.pop_back();
           }
};

//Time Limit Exceeded
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        queue<vector<string>> cur,next;
        vector<vector<string>> res;
        
        cur.push(vector<string>{beginWord});
        int l=beginWord.length();
        bool flag = false;

        while(!cur.empty()){
            if(flag) break;
            vector<string> level;
            while(!cur.empty()){
                vector<string> tmp = cur.front();
                string w = tmp.back();
                cur.pop();
                for(int i =0;i<l;i++)
                    for(char c ='a';c<='z';c++){
                        if(c == w[i]) continue;
                        swap(c,w[i]);
                        if (w == endWord) {
                            flag = true;
                            tmp.push_back(endWord);
                            res.push_back(tmp);
                            continue;
                        }
                        if(wordList.find(w)!=wordList.end()){
                            level.push_back(w);
                            tmp.push_back(w);
                            next.push(tmp);
                            tmp.pop_back();
                           }
                        swap(c,w[i]);
                    }
            }
            swap(cur,next);
            for(string s:level) wordList.erase(s);
        }
        return res;
    }
};
