//third
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string cur;
		dfs(s, cur, 0, 1, result);
		return result;
	}
private:
	void dfs(string& s, string cur, int pre, int step,vector<string> &result) {
		if(step == 5){
		    if(pre==s.size()){
		        cur.pop_back();
		        result.push_back(cur);
		    }
		    return;
		}
		if(pre>=s.size()) return;
		if(s[pre]=='0'){
		    string ss = cur;
		    ss+="0.";
		    dfs(s,ss,pre+1,step+1,result);
		}
		else{
		    for(int l = 1;l<=3;l++){
		        if((l+pre<=s.size()) && stoi(s.substr(pre,l))<=255){
		            string ss = cur;
		            ss+=s.substr(pre,l);
		            ss+=".";
		            dfs(s,ss,pre+l,step+1,result);
		        }
		    }
		}
	}
};
//modification of first
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.length() < 4) return result;
		string cur;
		dfs(s, cur, 0, 1,1, result);
		return result;
	}
private:
	void dfs(string& s, string cur, int pre, int end, int step,vector<string> &result) {
		
		if (pre == s.length()) {
			if (step == 5) {
				cur.pop_back();
				result.push_back(cur);
				return;
			} else return;
		}
		
		if (end - pre > 3||end>s.length()||step==5)
			return;
			
		if(s[pre]!='0') dfs(s, cur, pre, end + 1,step, result);
		
		if (stoi(s.substr(pre, end - pre)) <= 255) {
			cur += s.substr(pre, end - pre);
			cur+= '.';
			dfs(s, cur, end, end + 1, step+1,result);
		}
	}
};
//second
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.size()<4) return result;
        string cur;
        dfs(result,cur,s,0,1);
        return result;
    }
    
    void dfs(vector<string> &result,string cur,string &s,int i,int step){
        if(i==s.size()&&step==5){
            cur.pop_back();
            result.push_back(cur);
            return;
        } else if(i==s.size()||step==5) return;
        
        string tmp = cur;
        
        cur+=s[i];
        cur+='.';
        dfs(result,cur,s,i+1,step+1);
        if(s[i]=='0') return;
        
        if(s.size()-i>=2 && stoi(s.substr(i,2))<256) {
            cur=tmp;
            cur+=s.substr(i,2);
            cur+='.';
            dfs(result,cur,s,i+2,step+1);
        }
        if(s.size()-i>=3 && stoi(s.substr(i,3))<256) {
            cur=tmp;
            cur+=s.substr(i,3);
            cur+='.';
            dfs(result,cur,s,i+3,step+1);
        }
        
    }
};
//first
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.length() < 4)
			return result;
		string cur("");
		dfs(s, cur, 0, 1, result);
		return result;
	}
private:
	void dfs(string& s, string& cur, int pre, int end, vector<string> &result) {
		if (end - pre > 3)
			return;
		if (count_if(cur.begin(), cur.end(), bind1st(equal_to<char>(), '.'))
				== 4)
			return;
		if (end == s.length()) {
			if (stoi(s.substr(pre, end - pre)) <= 255
					&& count_if(cur.begin(), cur.end(),
							bind1st(equal_to<char>(), '.')) == 3
					&& (end - pre == 1
							|| (end - pre > 1
									&& s.substr(pre, end - pre)[0] != '0'))) {
				string tmp = s.substr(pre, end - pre);
				cur += tmp;
				result.push_back(cur);
				cur.erase(cur.size() - tmp.size(), tmp.size());
				return;
			} else
				return;
		}
		dfs(s, cur, pre, end + 1, result);
		if (stoi(s.substr(pre, end - pre)) <= 255
				&& (end - pre == 1
						|| (end - pre > 1 && s.substr(pre, end - pre)[0] != '0'))) {
			string tmp = s.substr(pre, end - pre) + '.';
			cur += tmp;
			dfs(s, cur, end, end + 1, result);
			cur.erase(cur.size() - tmp.size(), tmp.size());
		}
	}
};
