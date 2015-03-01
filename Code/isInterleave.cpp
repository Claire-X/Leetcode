//DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size()) return false;
        vector<bool>f(s2.size()+1);
        for(size_t j=0;j<s2.size()+1;j++){
            if(s2.substr(0,j)==s3.substr(0,j)) f[j]=true;
            else f[j]=false;

        }
        for(size_t i =1;i<s1.size()+1;i++){
            if(s1.substr(0,i)==s3.substr(0,i)) f[0]=true;
            else f[0] = false;
            for(size_t j =1;j<s2.size()+1;j++)
                f[j] = (f[j]&&s1[i-1]==s3[i+j-1]) || (f[j-1]&&s2[j-1]==s3[i+j-1]);
        }
        return f[s2.size()];
    }
};
