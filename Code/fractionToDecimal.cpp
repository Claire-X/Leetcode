//second 12ms map will be faster
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        bool neg = (numerator>>31)^(denominator>>31);
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        long long digit = n/d;
        n=n%d*10;
        string result;
        string integer(to_string(digit));
        vector<int> digits;
        while(n){
            auto it = find_if(digits.begin(),digits.end(),bind1st(equal_to<int>(),n));
            if(it!=digits.end()){
                result.insert(distance(digits.begin(),it),1,'(');
                result+=')';
                break;
            }else digits.push_back(n);
            digit = n/d;
            result+= digit+'0';
            n=n%d*10;;
        }
        if(neg) integer.insert(integer.begin(),1,'-');
        if(result.size()) {
            integer+='.';
            return integer+=result;
        }else return integer;
        
    }
};
//first 4ms
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (denominator == 0)
			return "";
		if (numerator == 0)
			return "0";
		bool isNegative = (denominator > 0) ^ (numerator > 0);
		long num = abs((long) numerator);
		long deno = abs((long) denominator);
		string decimal("");
		map<int, int> res;

		long remainder = num, quotient;
		while (remainder) {
			if (res.find(remainder) != res.end()) {
				decimal.insert(res[remainder], 1, '(');
				decimal += ')';
				break;
			}
			int tmp = remainder;
			quotient = remainder / deno;
			remainder = remainder % deno;

			res.insert(make_pair(tmp, decimal.length()));
			if (decimal.size() == 0) {
				decimal += to_string(quotient);
				decimal += '.';
			} else {
				decimal += to_string(quotient);
			}
			remainder *= 10;
		}
		if (isNegative)
			decimal.insert(decimal.begin(), '-');
		if (decimal.back() == '.')
			decimal.erase(--decimal.end());
		return decimal;
	}
};
