class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0)
			return false;
		if (x < 10)
			return true;
		int quotient = 0;
		int dr = 1;
		while (1) {
			dr *= 10;
			quotient = x / dr;
			if (quotient == 0) {
				dr /= 10;
				break;
			}
			if (dr == 1000000000) {
				break;
			}
		}
		int dl = 10;

		bool flag = true;
		int left, right;
		while (dr >= dl) {
			left = x % dl / (dl / 10);
			//cout<<"left"<<left<<endl;
			right = x / dr % 10;
			//cout<<"right"<<right<<endl;
			if (left == right) {
				dr /= 10;
				dl *= 10;
			} else {
				return false;
			}
		}
		return flag;

	}
};
