// 1、暴力法
// 对S1进行循环移位，再进行字符串包含的判断
char src[5] = "AABCD";
char des[5] = "CDAA";

int len = strlen(src);
for (int i = 0; i < len; i++) {
	char tempchar = src[0];
	for (int j = 0; j < len - 1; j++)
		src[j] = src[j + 1];
	src[len - 1] = tempchar;
	if (strstr(src, des) == 0) {
		return true;
	}
}
return false;

// 2、可以发现其实是判断s2是不是在s1s1中