class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {

        unordered_map<string,vector<string> > mapping;
        for(auto s:strs){
            auto key = s;
            sort(key.begin(),key.end());
            mapping[key].push_back(s);

        }
        vector<string> result;
        
        for(auto p:mapping)
            if(p.second.size()>1) 
                result.insert(result.end(),p.second.begin(),p.second.end());
       return result;
        
    }
};
