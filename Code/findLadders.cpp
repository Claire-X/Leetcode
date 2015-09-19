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
