class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        vector<string> line;
        size_t length=0;
        for(size_t i = 0;i<words.size();i++){
            if((length == 0 && length + words[i].size()<=L) ||length+words[i].size()+1 <=L){
                line.push_back(words[i]);
                length+= length==0?words[i].size():words[i].size()+1;
            }else{
            	i--;
            	string s;
            	if(line.size()==1) {
            		s+=line[0] + string(L-line[0].size(),' ');
            	}else{

            		int space = (L-length +line.size()-1)/(line.size()-1);
            		int tail = (L-length +line.size()-1)%(line.size()-1);
            		for(int i =0;i<line.size();i++){
            			if(i==line.size()-1) {
            				s+=line[i];
            			}
            			else{
            				s+=(line[i] + string(space,' '));
            				if(tail>0) {s+=" ";tail--;}
            			}
            		}
            	}
            	result.push_back(s);
            	line.clear();
            	length = 0;
            }
        }
        if(!line.empty()){
        	string s;
        	for(size_t i =0;i<line.size();i++){
        	     if(i==line.size()-1) {
        	          s.append(line[i]);
        	          s.append(L-s.size(),' ');
        	          result.push_back(s);
        	     }
        	     else s+= line[i]+" ";
        	}
        }

        return result;
    }
};
