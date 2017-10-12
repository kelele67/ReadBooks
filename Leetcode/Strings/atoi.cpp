class Solution {
	public:
		int strToInt(const char *str) {
			static const int MAX_INT = (int)((unsigned)~0 >> 1);
			static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
			if (str == 0) {
				return 0;
			}

			while (isspace(*str)) {
				++str;
			}

			int sign = 1;
			if (*str == '+' || *str == '-') {
				if (*str == '-') {
					sign = -1;
				}
				++str;
			}

			while(isdigit(*str)) {
				//处理溢出
				int c = *str - '0';
				if (sign > 0 && (n > MAX_INT / 10 || n == MAX_INT / 10 && c > MAX_INT % 10)) {
					n = MAX_INT;
					break;
				} else if (
					sign < 0 && (n > (unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10))) {
					n = MIN_INT;
					break;
					}
				n = n * 10 + c;
				++str;
			}
			return sign > 0 ? n : -n;
}
