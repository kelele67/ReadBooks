class Solution {
public:
	int strStr(const string& haystack, const string& needle) {
		return kmp(haystack.c_str(), needle.c_str());
	}

private:
	//next数组计算
	static void compute_prefix(const char *pattern, int next[]) {
		int i;
		int j = -1;
		const int m = strlen(pattern);

		next[0] = j;
		for (i = 1; i < m; i++) {
			//失配的操作
			//递归调用next，直到整个pattern再无最长前缀或者找到一个之前的满足条件的最长前缀
			while (j > -1 && pattern[j + 1] != pattern[i])  j = next[j]; 

			if (pattern[i] == pattern[j + 1]) j++;
			//j表示既是自身真后缀又是最长前缀的字符串长度
			next[i] = j;
		}
	}

	//kmp算法
	static int kmp(const char *text, const char *pattern) {
		int i;
		int j = -1;
		const int n = strlen(text);
		const int m = strlen(pattern);
		if (n == 0 && m == 0) return 0;
		if (m == 0) return 0;
		//创建next数组
		//int *next = (int*)malloc(sizeof(int) *m);
		int *next = new int[m];

		compute_prefix(pattern, next);

		for (i = 0; i < n; i++) {
			while (j > -1 && pattern[j + 1] != text[i]) j = next[j];

			if (text[i] == pattern[j + 1]) j++;
			//记得free
			if (j == m - 1) {
				//free(next);
				delete []next;
				return i-j;
			}
		}
		delete []next;
		//free(next);
		return -1;
	}
};