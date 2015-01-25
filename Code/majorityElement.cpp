class Solution {
public:
    int majorityElement(vector<int> &num) {
    	map<int,int> counts;
        int element;
        int max = 0;
        for(auto n:num){
            if(counts.find(n) == counts.end()) {
            	int key=n;
            	counts.insert(std::make_pair<int,int>(int(key),1));
            }
            else{
                counts.find(n)->second++;
            }
            if(max<counts.find(n)->second) {
                max = counts.find(n)->second;
                element=n;
            }
        }
        return element;
    }
};
