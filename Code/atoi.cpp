class Solution {
public:
	int atoi(const char *str) {
		bool flag = false;
		int i = 0;
		int length = strlen(str);
		for (; i < length; i++) {
			if (str[i] == ' ')
				continue;
			else {
				flag = true;
				break;
			}
		}
		if (!flag)
			return 0;
		int sign = 1;

		if (str[i] == '-') {
			sign = -1;
			i++;
		} else if (str[i] == '+')
			i++;

		if (str[i] > '9' || str[i] < '0')
			return 0;

		int total = 0;
		for (; i < length; i++) {
			if (str[i] < '0' || str[i] > '9')
				break;
			if (total > INT_MAX / 10
					|| (total == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
				return sign == -1 ? INT_MIN : INT_MAX;
			total = total * 10 + (str[i] - '0');
		}

		return total * sign;

	}
};
