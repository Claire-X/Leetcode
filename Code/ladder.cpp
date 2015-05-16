//Second time
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<string> cur,next;
        cur.push(beginWord);
        int level = 1,l=beginWord.length();
        unordered_set<string> visit;

        while(!cur.empty()){
            while(!cur.empty()){
                string w = cur.front();
                cur.pop();
                for(int i =0;i<l;i++)
                    for(int j =0;j<26;j++){
                        char c = 'a'+j;
                        if(c == w[i]) continue;
                        swap(c,w[i]);
                        if (w == endWord) return level+1;
                        if(wordDict.find(w)!=wordDict.end())
                            {next.push(w);
                            wordDict.erase(w);}
                        swap(c,w[i]);
                    }
            }
            level++;
            swap(cur,next);
        }
        return 0;
    }
};
//first
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end) return 1;
        if(dict.size()==0) return 0;
        queue<pair<string,int> > q;
        unordered_set<string> visited;

        q.push(pair<string,int>(start,1));


        while(!q.empty()){
            string s = q.front().first;
            int level = q.front().second;
            q.pop();
            visited.insert(s);
            for(size_t i =0;i<s.size();i++){

                for(char c = 'a';c<='z';c++){
                    if(c == s[i]) continue;
                    swap(c,s[i]);
                    if(s == end)
                      return level + 1;

                    if(dict.find(s) != dict.end() && visited.count(s)==0){
                        q.push(pair<string,int>(s,level+1));
                        dict.erase(s);
                    }
                    swap(c,s[i]);
                }
            }

        }
        return 0;
    }
};
