struct myclass {
	  bool operator() (string a,string b){
	        return a+b > b+a ? true:false;
	  }
	} myobject;

class Solution {
public:
	string largestNumber(vector<int> &num) {
        if(num.size() == 0) return "0";
        vector<string> vs;
        for(auto it:num)
            vs.push_back(to_string(it));
        sort(vs.begin(),vs.end(),myobject);
        string largest("");
        for(auto it:vs)
            largest+=it;
        return largest[0]=='0'?"0" : largest;
    }

};
