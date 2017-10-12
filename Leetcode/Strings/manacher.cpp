//最长回文子串
const int maxn = 1000010;
char str[maxn];
char tmp[maxn << 1];
int len[maxn << 1];

int INIT(char *str) {
	int i, len = strlen(str);
	//开头增加一个特定字符，防止越界
	tmp[0] = '$';
	for (i = 1; i <= 2 * len; i += 2) {
		tmp[i] = '#';
		tmp[i + 1] = str[i / 2];
	}
	tmp[2 * len + 1] = '#';
	tmp[2 * len + 2] = '^';
	tmp[2 * len + 3] = 0;
	return 2 * len + 1;
}

//manacher
int MANACHER(char *str, int len) {
	int p[1000];
	int mx = 0, id = 0;
	for (int i = 1; i <= len; i++) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (s[i + p[i]] == s[i - p[i]]) {
			p[i]++;
		}
		
		if (i + p[i] > mx) {
			mx = i + p[i];
			id = i;
		}
	}
	return p[i] - 1;
}
