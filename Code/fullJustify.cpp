//第二种写法的代码精简 generalize the 3 cases in the second into one single loop 
class Solution {
  public:
      vector<string> fullJustify(vector<string>& words, int maxWidth) {
          vector<string> res;
          int n = words.size(),l = 0,i=0;
          while(i<n){
              int j = i;
              l=0;
              while(j<=n){
                  if(j<n && (int)words[j].size() <= maxWidth-(l+j-i)){
                      l+=words[j].size();
                      j++;
                  }else{
                	  j--;
                      string line = words[i];
                      for(int k = 0;k<j-i;k++){
                          if(j<n-1){
                            line+=string((maxWidth-l)/(j-i),' ');
                            if(k<(maxWidth-l)%(j-i)) line+=' ';}
                          else line+=" "; 
                        line+=words[i+k+1];
                      }
                	  line+=string(maxWidth-line.size(),' ');
                      res.push_back(line);
                      break;
                  }
              }
              i = j+1;
          }
          return res;
      }
  };
//second time
class Solution {
  public:
      vector<string> fullJustify(vector<string>& words, int maxWidth) {
          vector<string> res;
          int n = words.size(),l = 0,i=0;
          while(i<n){
              int j = i;
              l=0;
              while(j<n){
                  if((int)words[j].size() <= maxWidth-(l+j-i)){ //spent an hour for this bug :( pay attention to
                      l+=words[j].size();                       // the comparison between size_t amd int, especially when                     
                      j++;                                      //negtive value is involved.                                    
                  }else if(j>i+1){ //case 1: line contains more than one word
                	  j--;
                      int space = (maxWidth-l)/(j-i);
                      int leftspace = (maxWidth-l)%(j-i);
                      string line;
                      for(;i<=j;i++){
                          line+=words[i];
                          if(i!=j){
                              line+=string(space,' ');                                    //constructor of string
                              if(leftspace>0) {line+=' ';leftspace--;}
                          }
                      }
                      res.push_back(line);
                      break;
                  }else {//case 2: line contains only one word
                	  j--;
                	  string line=words[i];
                	  int space = maxWidth-words[i].size();
                	  line+=string(space,' ');
                	  res.push_back(line);
                	  break;
                  }
              }
              if(j<n) i = j+1;
              else {//case 3: the last line
                  string line;
                  for(;i<n;i++){
                      line+=words[i];
                      if(i!=n-1) line+=" ";
                      else line+=string(maxWidth-line.size(),' ');
                  }
                  res.push_back(line);
                  break;
              }
          }
          return res;
      }
  };
  
//First
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        size_t length=0,start=-1,end=-1;
        for(size_t i = 0;i<words.size();i++){
            if((length == 0 && length + words[i].size()<=L) ||length+words[i].size()+1 <=L){
                if(length==0) start = i;
                length+= length==0?words[i].size():words[i].size()+1;
            }else{
            	i--;
            	end = i;
            	string s;
            	if(start==end) {
            		s+=words[start] + string(L-words[start].size(),' ');
            	}else if(end!=words.size()-1){

            		int space = (L-length +end-start)/(end-start);
            		int tail = (L-length +end-start)%(end-start);
            		for(int i =start;i<=end;i++){
            			if(i==end) {
            				s+=words[i];
            			}
            			else{
            				s+=(words[i] + string(space,' '));
            				if(tail>0) {s+=" ";tail--;}
            			}
            		}
            	}
            	result.push_back(s);
            	length = 0;
            	start = -1;
            	end=-1;
            }
        }
        if(start!=-1){
        	string s;
        	for(size_t i =start;i<words.size();i++){
        	     if(i==words.size()-1) {
        	          s.append(words[i]);
        	          s.append(L-s.size(),' ');
        	          result.push_back(s);
        	     }
        	     else s+= words[i]+" ";
        	}
        }

        return result;
    }
};
