class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> select(256,false);
        int start=0,ml=0;
        for(int i=0;i<s.size();i++){
            if(!select[s[i]]){
                select[s[i]] = true;
                ml = max(i-start+1,ml);
            }else{
                while(s[start]!=s[i]) {
                    select[s[start]] = false;
                    start++;
                }
                 start++;
            }
        }
        return ml;
    }
};
