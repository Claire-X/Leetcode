class Solution {
public:
    bool isNumber(string s) {
        enum InputType{invalid,space,sign,digit,dot,e};
        int trans[][6]{
            {-1,0,3,1,2,-1},    //0 初始状态或只有空格
            {-1,8,-1,1,4,5},    //1 前面只有数字
            {-1,-1,-1,4,-1,-1}, //2 前面只有一个dot
            {-1,-1,-1,1,2,-1},  //3 前面只有sign
            {-1,8,-1,4,-1,5},   //4 前面有数字和dot（前一位可是数字也可是dot，和2的区别在于可作为终态，避免了单个dot“.”）
            {-1,-1,6,7,-1,-1},  //5 前面刚输入e
            {-1,-1,-1,7,-1,-1}, //6 e后面有sign （和3区别在于不可有dot）
            {-1,8,-1,7,-1,-1},  //7 e后有数字（和1区别在于不可有dot和e）
            {-1,8,-1,-1,-1,-1}  //8 有效输入和空格
        };
        int state = 0;
        for(auto i:s){
            InputType input=invalid;
            if(isspace(i)) input = space;
            else if(isdigit(i)) input = digit;
            else if(i=='+'||i=='-') input = sign;
            else if(i=='.') input = dot;
            else  if(i=='e'||i=='E') input = e;
            
            state = trans[state][input];
            if(state == -1) return false;
        }
        
        return state == 8|| state == 1 || state == 7 ||state == 4;
        
    }
};
