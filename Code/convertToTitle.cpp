class Solution {
public:
    string convertToTitle(int n) {
     int quotient=n;
     int remainder;
     stack<int> res;
     string num;

     while(quotient){
         remainder=quotient%26;
         if(remainder) res.push(remainder);
         else{
        	 res.push(26);
        	 quotient--;
         }
         quotient/=26;
     }

     while(!res.empty()){
    		 num+='A'+res.top()-1;
    	     res.pop();
    	 }


     return num;
    }
};
