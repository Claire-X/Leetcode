//
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> letters;
        vector<bool> visit(26,false);
        for(char c:s){
            letters[c]++;
        }
        string res = "0";
        for(int i=0;i<s.size();i++){
            letters[s[i]]--;
            if(visit[s[i]-'a']) continue;
            while(s[i]<res.back() && letters[res.back()]){
                visit[res.back()-'a']=false;
                res.pop_back();
            }
            res.push_back(s[i]);
            visit[s[i]-'a']=true;
            
        }
        return res.substr(1);
    }
};
