class Solution {
public:
    string multiply(string num1, string num2) {
      if(num1=="0" || num2=="0") return "0";
      vector<string> tmp;
      int n = num2.size();
      for(int i=n-1;i>=0;i--){
         string suffix(n-1-i,'0');
         tmp.push_back(multiply(num1,num2[i])+suffix);
      }
      string result = tmp[0];
      for(int i =1;i<tmp.size();i++){
          result = add(result,tmp[i]);
      }
      return result;
    }
private:
    string multiply(string num1,char c){
        int multiplier = c-'0',carry = 0;
        string result("");
        for(auto it = num1.rbegin();it!=num1.rend();it++){
            int tmp = (*it-'0')*multiplier+carry;
            result +=(tmp%10+'0');
            carry = tmp/10;
        }
        if(carry) result+= (carry+'0');
        reverse(result.begin(),result.end());
        return result;
    }
    string add(string num1,string num2){
        int carry =0;
        string result("");
        auto it1 = num1.rbegin(),it2 = num2.rbegin();
        for(;it1!=num1.rend()&&it2!=num2.rend();it1++,it2++){
            int tmp = (*it1-'0')+(*it2-'0')+carry;
            result+= (tmp%10+'0');
            carry = tmp/10;
        }
        while(it1!=num1.rend()){
            int tmp = (*it1-'0')+carry;
            result+= (tmp%10+'0');
            carry = tmp/10;
            it1++;
        }
        while(it2!=num2.rend()){
            int tmp = (*it2-'0')+carry;
            result+= (tmp%10+'0');
            carry = tmp/10;
            it2++;
        }
        if(carry) result+= (carry+'0');
        reverse(result.begin(),result.end());
        return result;
    }
};
