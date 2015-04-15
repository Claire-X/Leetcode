//second
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur(1,1),next;
        for(int i =0;i<rowIndex;i++){
            next.push_back(1);
            for(int j =0;j<cur.size()-1;j++)
                next.push_back(cur[j]+cur[j+1]);
            next.push_back(1);
            cur=next;
            next.clear();
        }
        
        return cur;
        
            
    }
};
//first
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> pre(1,1);
		if (rowIndex == 0)
			return pre;
		vector<int> current;
		for (int r =1; r <= rowIndex; r++) {
			for (int i = 0; i < r+1; i++) {
				if (i == 0 || i == r )
					current.push_back(1);
				else {
					current.push_back(pre[i - 1] + pre[i]);
				}
			}
			pre = current;
			current.clear();
		}
		return pre;

	}
};
