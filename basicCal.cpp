// take advantage of only having '+' and '-'
class Solution {
public:
    int calculate(string s) {
        int ans=0;
        int sign=1;
        stack<int> signs;
        signs.push(1);
        int num=0;
        for(auto i:s){
            if(isdigit(i))
                num = num*10+(i-'0');
            else if(i==' ') continue;
            else if(i == '+'||i=='-'||i==')') {
                ans += num*sign*signs.top();
                num = 0;
                if(i == '+')sign =1;
                else if(i=='-') sign = -1;
                else signs.pop();
            }else if(i=='(') {
                signs.push(sign*signs.top());
                sign =1;
            }
        }
        if(num!=0)  ans+=num*sign*signs.top();
        return ans;
    }
};

// two stack solution, more 
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int num=0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c==' ') continue;
            if(c == '+'||c=='-'||c=='(') {
                ops.push(c); continue;
            }
            // only perform calculation when a brace is ended or a right operator is added
            if(c ==')') {
                ops.pop();
            }else{
                num = num*10+(c-'0');
                if(i<s.size()-1 && isdigit(s[i+1])) continue;
                nums.push(num);
                num=0;
            }
            // If, however, there is no more computational operators in stack
            // then either we have just added the LEFT operand, or if the braced block just terminated is a LEFT operand.
            // Either way, we cannot do computation yet.
            if(ops.empty()||ops.top()=='(') continue; 
            int opr = nums.top();
            nums.pop();
            if(ops.top()=='+')
                nums.top()+=opr;
            else nums.top()-=opr;
            ops.pop();
        }
        return nums.top();

    }
};
