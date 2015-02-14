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
