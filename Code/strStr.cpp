class Solution {
public:
    int strStr(char *haystack, char *needle) {
        string str(haystack);
        string s(needle);
        return str.find(s);
    }
};
