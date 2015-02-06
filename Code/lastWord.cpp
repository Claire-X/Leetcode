class Solution {
public:
    int lengthOfLastWord(const char *s) {

        string str(s);
        reverse(str.begin(),str.end());
        auto i = find_if(str.begin(),str.end(),::isalpha);
        auto j = find_if(i+1,str.end(),::isspace);
        return distance(i,j);
        
    }
};
