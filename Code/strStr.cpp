class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (!(*needle))
			return 0;

		int i = 0, j = 0;
		int index = -1,tmp;
		while (haystack[i]) {
			if (haystack[i] != needle[j]) {
				i++;
			} else {
				index = i;
				while (haystack[i] && needle[j]) {
					if (haystack[i] != needle[j]) {
						j = 0;
						i=index+1;
						index = -1;
						break;
					} else {
						i++;
						j++;
					}
				}

				if (!needle[j]) {
					return index;
				} else if (!haystack[i]) {
					index = -1;
				}
			}

		}

		return index;

	}
};
