//cantor unfold
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==1) return "1";
        vector<int> select(n);
        iota(select.begin(),select.end(),1);
        string result;
        k--;
        while(n){

            int digit = k/factor(n-1);
            k%=factor(n-1);
            
            result+=*next(select.begin(),digit)+'0';
            select.erase(next(select.begin(),digit));
            n--;
        }
        return result;
    }

    int factor(int n){
        int sum = 1,i=1;
        while(++i<=n)
           sum*=i;
        return sum;
    }
};


//math
class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        vector<int> f(n);
        vector<bool> select(n,false);
        f[0]=1;
        for(int i=1;i<n;i++)
            f[i]=f[i-1]*i;
        string result;
        for(int i=n-1;i>=0;i--){
            int x = k/f[i];
            k%=f[i];
            int j=0,s=0;
            for(;j<n;j++)
                if(!select[j]){
                    if(s==x) {
                        select[j]=true;
                        break;
                    }
                    s++;
                }
            result+='0'+(j+1);
        }
        return result;
        
    }
};
