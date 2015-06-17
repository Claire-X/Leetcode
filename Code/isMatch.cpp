//recursion (Time limit exceeded)
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        return dfs(s,p,0,0);
    }
    bool dfs(const char *s, const char *p,int poss,int posp){
        while(s[poss]==p[posp]||p[posp]=='?') {
            if(poss==strlen(s)-1&&posp==strlen(p)-1) return true;
            poss++;
            posp++;
        }
        bool flag = false;
        if(p[posp]=='*'){
            if(posp == strlen(p)-1) return true;
            else{
                while(p[posp]=='*') posp++;
                for(int i = poss;i<strlen(s);i++)
                 if(s[i] == p[posp])
                    if(dfs(s,p,i,posp+1))
                        flag =true;
            }
        }
        return flag;

    }
};

//iteration 
//关键在于:1
//p每遇到一个*，就保留住当前*的坐标和s的坐标，然后s从前往后扫描，如果不成功，则s++,重新扫描。
//2只要记录最后一个*就可以了，因为*可以匹配所有，如果*后面的没匹配上，就是*之后的问题，即使退回之前的*，情况只会更差。
//换句话说，能走到最后一个*，肯定前面都成功匹配了，因此如果s和p是可以匹配的，那么从最后一个*再开始扫描肯定可以匹配
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star=NULL,*str;
        while(*s){
            if(*p=='?'||*s==*p){s++;p++;continue;}
            if(*p=='*'){
                while(*p=='*') p++;
                if(*p=='\0') return true;
                star = p-1;
                str = s;
                continue;
            }
            if(!star) return false;
            else {
                str++;
                s=str;
                p=star+1;
            }
        }
        while(*p=='*') p++;
        return *p=='\0';
        
    }
};

//简单写法
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         
        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }
};
