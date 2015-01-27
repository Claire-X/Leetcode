
class Solution {
public:
	vector<int> split(string s){
			vector<int> v;
			string ss="";
			for(size_t i=0;i<s.length();i++){
			            if(s[i] == '.'){
			            v.push_back(atoi(ss.c_str()));
			                ss.clear();
			            }
			            else if(i == s.length()-1){
			            	ss+=s[i];
			            	v.push_back(atoi(ss.c_str()));
			            }
			            else ss += s[i];
			        }
			return v;
		}
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        v1=split(version1);
        v2=split(version2);
        
         if(v1.size()>v2.size())
             for(int i=0;i<v1.size()-v2.size();i++) 
                 v2.push_back(0);
                 
         if(v1.size()<v2.size())
             for(int i=0;i<v2.size()-v1.size();i++) 
                 v1.push_back(0);

        size_t i=0;
        while(i<v1.size()&& i<v2.size()){
            if(v1[i] > v2[i]) return 1;
            else if(v1[i] < v2[i]) return -1;
            i++;
        }


        return 0;

    }
};
