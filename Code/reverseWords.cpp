//in-place in O(1) space
class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        if(!n) return ;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                int last = i,first=i;
                for(;first>=0;first--)
                    if(s[first]==' ') break;
                first++;
                string word=s.substr(first,last-first+1);
                s+=" ";
                s+=word;
                i = first;
                s.erase(first,word.size());
           }
           else s.erase(i,1);
       }
       s.erase(0,1);
    }
};
//trivial solution
class Solution {
public:
	void reverseWords(string &s) {
		int i = s.length() - 1;
		string rs;
		while (i >= 0) {
			while (s[i] == ' ' && i >= 0)
				i--;
			if (i < 0)
				break;
			int start = i;
			while (s[i] != ' ' && i >= 0)
				i--;
			string word = s.substr(i + 1, start - i);
			if (rs != "")
				rs += ' ';
			rs.append(word);
		}
		s = rs;
	}
};
