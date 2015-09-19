//divide the number on the position of 'e', the left part should be a float and the right part should be an integer
class Solution {
public:
    bool isNumber(string s) {
        int i =0,j=s.size()-1;
        while (i<s.size() && s[i]==' ') i++;
        while (j>=0 && s[j]==' ') j--;
        s = s.substr(i,j-i+1);
        i=0;
        while(i<s.size() && s[i]!= 'e') i++;
        
        if(i!=s.size()){
            string left = s.substr(0,i),right = s.substr(i+1,s.size()-i-1);
            return isNumber(left,true)&&isNumber(right,false);
        }else return isNumber(s,true);
    }
    bool isNumber(string s,bool left){
        if(s.size()==0) return false;
        if(s[0] == '+' || s[0]=='-') s = s.substr(1,s.size()-1);
        if(s.size()==0) return false;
        bool dot=false;
        
        for(int i = 0;i<s.size();i++){
            if(isdigit(s[i])) continue;
            else if(s[i]=='.' && left){
                if(dot) return false;
                dot = true;
                if((i>0 && isdigit(s[i-1])) || (i<s.size()-1 && isdigit(s[i+1]))) continue;
                else return false;
            }else return false;
        }
        
        return true;
    }
};
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
