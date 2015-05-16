//second time
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict{" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result{""},tmp;
        for(char d:digits){
            for(char c: dict[d-'0']){
            	for(string s:result){
            		tmp.push_back(s+=c);
                    s.pop_back();
                }
            }
            result.clear();
            swap(result,tmp);
         }
        if(result.size()==1) result.pop_back();
        return result;
    }
};
//first time
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return vector<string>(1,"");
    vector<string> touche({" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
    vector<string> current,next;
    for(size_t i=0;i<digits.size();i++){
       if(i == 0){
           for(auto c:touche[digits[i]-'0'])
               current.push_back(string(1,c));
       }
       else{
           for(char c:touche[digits[i]-'0'])
               for(auto s : current){
                   next.push_back(s+=c);
               }
           if(i==current.size()-1) return current;
           current.clear();
           swap(current,next);
       }
    }
    return current;
    }
};
