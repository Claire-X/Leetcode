//scan from center
class Solution {
public:
    string longestPalindrome(string s) {
       string p("");
       for(size_t i =0;i<s.size();i++) {
           for(size_t left=i,right=i+1;left>=0 && right<s.size();left--,right++){
               if(s[left] != s[right]) {
                   left++;
                   right--;
                   if(right-left+1>p.size()) p=s.substr(left,right-left+1);
                   break;
               }
               if(right==s.size()-1 || left == 0)
            	   if(right-left+1>p.size()) p=s.substr(left,right-left+1);

           }

           for(size_t left=i,right=i;left>=0 && right<s.size();left--,right++){
               if(s[left] != s[right]) {
                   left++;
                   right--;
                   if(right-left+1>p.size()) p=s.substr(left,right-left+1);
                   break;
               }
               if(right==s.size()-1 || left == 0)
                       	   if(right-left+1>p.size()) p=s.substr(left,right-left+1);
           }
       }
       return p;
    }
};

// DP solution
class Solution {
public:
	string longestPalindrome(string s) {
		int length = s.size();
		int start = 0, max_p = 0;
		bool p[length][length];
		fill_n(&p[0][0], length * length, false);
		for (int i = length - 1; i >= 0; i--) {
			for (int j = i; j < length; j++) {
				p[i][j] = (s[j] == s[i] && (j - i <= 2 || p[i + 1][j - 1]));
				if (p[i][j] && j - i + 1 > max_p) {
					max_p = j - i + 1;
					start = i;
				}

			}
		}
		return s.substr(start, max_p);
	}
};
