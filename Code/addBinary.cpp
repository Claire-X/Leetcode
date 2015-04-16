//second
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1;
        int carry = 0;
        string s;
        while(i>=0||j>=0){
            int x = i>=0?a[i]-'0':0;
            int y = j>=0?b[j]-'0':0;
            int sum = (carry+x+y)%2;
            carry = (carry+x+y)/2;
            s+= sum+'0';
            i--;j--;
        }
        if(carry) s+='1';
        reverse(s.begin(),s.end());
        return s;
    }
};


//first
class Solution {
public:
	string addBinary(string a, string b) {

		if (a.size() < b.size()) {
			string c(b.size() - a.size(), '0');
			c.append(a);
			a = c;
		}
		if (b.size() < a.size()) {
			string c(a.size() - b.size(), '0');
			c.append(b);
			b = c;
		}

		auto ia = a.rbegin();
		auto ib = b.rbegin();

		string sum = "";
		int carry = 0;
		while (ia != a.rend()) {
			int ai = (*ia) - '0';
			int bi = (*ib) - '0';
			int val = (ai + bi + carry) % 2;
			//cout<<val<<endl;
			sum += ('0' + val);
			carry = (ai + bi + carry) / 2;
			//cout<<carry<<endl;
			ia++;
			ib++;
		}
		if (carry)
			sum += '1';
		reverse(sum.begin(), sum.end());
		return sum;

	}
};
