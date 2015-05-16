//second
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur;
        generate(0,0,n,result,cur);
        return result;
    }
    void generate(int left, int right, int n, vector<string> &result,string &cur){
        if(left>n) return;
        if(left == n&&right == n){
                result.push_back(cur);
                return;
            }
        if(left>right) {
            cur.push_back(')');
            generate(left,right+1,n,result,cur);
            cur.pop_back();
        }
        cur.push_back('(');
        generate(left+1,right,n,result,cur);
        cur.pop_back();
    }
    
};

//first
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if(n==0) return result;
		generateParenthesis(n, 0, 0, "", result);
		return result;

	}
	void generateParenthesis(int n, int left, int right, string cur,
			vector<string> &result) {
		if (left == n) {
			while (++right <= n) {
				cur += ')';
			}
			result.push_back(cur);
			return;
		}

		if (left == right) {
			generateParenthesis(n, left + 1, right, cur + '(', result);
		}

		if (left > right) {
			generateParenthesis(n, left + 1, right, cur + '(', result);
			generateParenthesis(n, left, right + 1, cur + ')', result);
		}
	}
};
