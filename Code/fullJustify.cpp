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
