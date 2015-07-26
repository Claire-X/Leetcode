//first perform multiplication and division, then do addtion and subtraction in the second loop
class Solution {
public:
    int calculate(string s) {
        deque<int> nums;
        deque<char> ops;
        int num = 0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(isdigit(c)){
                num = num*10+(c-'0');
                if(i==s.size()-1||!isdigit(s[i+1])){
                    nums.push_back(num);
                    num=0;
                    if(!ops.empty()){
                        if(ops.back()=='*'||ops.back()=='/'){
                            int a = nums.back();
                            nums.pop_back();
                            if(ops.back()=='*') nums.back()*=a;
                            else if(ops.back()=='/') nums.back()/=a;
                            ops.pop_back();
                        }
                    }
                }
            } else if(c==' ')
                continue;
            else ops.push_back(c);
        }
        while(!ops.empty()){
            char op = ops.front();
            ops.pop_front();
            int a = nums.front();
            nums.pop_front();
            if(op=='+') nums.front()+=a;
            else nums.front() = a-nums.front();
        }
        return nums.front();
    }
};

//solution 2, similar to Basic Calculator
class Solution {
public:
    int calculate(string s) {
        char op = '#';
        int sign = 1,num = 0,n=0,total = 0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(isdigit(c)){
                n = n*10+(c-'0');
                if(i==s.size()-1||!isdigit(s[i+1])){
                    if(op!='#'){
                        if(op=='*') num*=n;
                        else if(op=='/') num/=n;
                        op = '#';
                        n=0;
                    }else {
                        num=n;
                        n=0;
                    }
                }
            } else if(c==' ')
                continue;
            else if(c=='*'||c=='/') op=c;
            else{
                total+=num*sign;
                if(c=='+') sign = 1;
                else sign=-1;
                num=0;
                op = '#';
            }
        }
        total+=num*sign;
        return total;
    }
};
