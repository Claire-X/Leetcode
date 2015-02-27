//把str1(i)转换为str2(j)的最后一步有三（四）种可能性，replace、add、delete（什么也不做）
//（此题可以与climb stairs的最后跳一步、跳两步类比）
//如果str1[i]==str2[j] 则f[i][j]==f[i-1][j-1] 
//如果通过replace 则f[i][j]==f[i-1][j-1]+1
//如果通过delete f[i][j]=f[i-1][j]+1;
//如果通过add则f[i][j]=f[i][j-1]+1;
//抽象地想，对于由初态经过一系列种类有限的重复操作到达终态的问题，可以考虑DP
//DP
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > f(word1.size()+1,vector<int>(word2.size()+1));
        for(size_t i =0;i<=word1.size();i++)
            f[i][0]=i;
        for(size_t j =0;j<=word2.size();j++)
            f[0][j]=j;
        for(size_t i =1;i<=word1.size();i++)
            for(size_t j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1])  f[i][j]=f[i-1][j-1];
                else{
                    f[i][j]=min(f[i-1][j-1]+1,f[i-1][j]+1);
                    f[i][j]=min(f[i][j],f[i][j-1]+1);
                }
                
            }
        return f[word1.size()][word2.size()];
        
    }
};
//滚动数组
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> f(word2.size()+1);
        int topright;
        
        for(size_t j =0;j<word2.size()+1;j++){
            f[j]= j;
        }

        for(size_t i =1;i<=word1.size();i++){
            topright = f[0];
            f[0] = i;
            for(size_t j = 1;j<=word2.size();j++){
                int tmp = f[j];
                if(word1[i-1]==word2[j-1])
                    f[j]=topright;
                else{
                    f[j]=min(topright,min(f[j],f[j-1]))+1;
                    }
                topright = tmp;
            }
        }
        return f[word2.size()];
    }
};
