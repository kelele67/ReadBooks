#include<iostream>

using namespace std;

double atof(const char *str) {
	double s = 0.0;
	double d = 10.0;
	int count = 0;

	int sign = 1;

	if (str == 0) {
		return 0;
	}

	while(*str == ' ') {
		str++;
	}

	if (*str == '-') {
		sign = -1;
		str++;
	}

	if (!*str >= '0' && *str <= '9') {
		return s;
	}

	//计算小数点前整数部分
	while (*str >= '0' && *str <= '9' && *str != '.') {
		s = s * 10.0 + *str - '0';
		str++;
	}

	//小数部分
	if (*str == '.'){
		str++;
	}

	//计算小数部分
	while (*str >= '0' && *str <= '9') {
		s = s + (*str - '0') /d;
		d *= 10.0;
		str++;
	}

	//考虑科学计数法
	if (*str == 'e' || *str == 'E') {
		str++;
		if (*str == '+') {
			str++;
			while (*str >= '0' && *str <= '9') {
				count = count * 10 + *str - '0';
				str++;
			}
			while (count > 0) {
				s *= 10;
				count--;
			}
		}

		if (*str == '-') {
			str++;
			while (*str >= '0' && *str <= '9') {
				s = s * 10 + *str - '0';
				str++;
			}
			while (count > 0) {
				s /= 10;
				count--;
			}
		}
	}
	return sign>0 s : -s
}
