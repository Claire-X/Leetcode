//O(n*m)
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {

        int wlen = L[0].size(),clen = wlen*L.size();

        vector<int> result;
        unordered_map<string,int> expect;
        for(auto word:L) expect[word]++;
        for(int i = 0;i<=(int)S.length()-clen;i++){
            unordered_map<string,int> appear;
            for(size_t j = i;j<i+clen;j+=wlen){
                string s = S.substr(j,wlen);
                if(expect.find(s)!=expect.end()&&appear[s]<expect[s]){
                    appear[s]++;
                }else break;
                if(j == i+clen-wlen)
                    result.push_back(i);
                }

            }
        return result;

    }
};
//O(n)
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {

        int wlen = L[0].size(),clen = wlen*L.size();

        vector<int> result;
        unordered_map<string,int> expect;
        for(auto word:L) expect[word]++;
        for(int i =0;i<wlen;i++){
            int start = i, appeared =0;
            unordered_map<string,int> appear;
            for(int j =i;j<=(int)S.length()-wlen;j+=wlen){
                string s=S.substr(j,wlen);
                if(expect.find(s)!=expect.end()){
                    if(expect[s]>appear[s]){
                    appear[s]++;
                    appeared++;
                    }else{
                        while(1){
                            string ss = S.substr(start,wlen);
                            if(ss==s) {start+=wlen;break;}
                            appear[ss]--;
                            appeared--;
                            start+=wlen;
                        }
                    }
                    if(appeared == L.size())
                        result.push_back(start);
                }else{
                    appear.clear();
                    start = j+wlen;
                    appeared = 0;
                }

            }
        }

        return result;

    }
};
