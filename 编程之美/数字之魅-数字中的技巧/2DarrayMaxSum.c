// 1、暴力法 O( N^2 * M ^2  * Sum的时间复杂度)
int max(int x, int y) {
	return (x > y) ? x : y;
}

int MaxSum(int *A, int n, int m) {
	maximum = -INF;
	for (i_min = 1; i_min <= n; i_min++)
		for (i_max = i_min; i_max <= n; i_max++)
			for (j_min = 1; j_min <= m; j_min++)
				for (j_max = j_min; j_max <= m; j_max++)
					maximum = max(maximum, Sum(i_min, i_max, j_min, j_max));
	return maximum;
}

// 预先计算部分和
for (i = 0; i <= n; i++)
	PS[i][0] = 0;
for (j = 0; j <= M; j++)
	PS[0][j] = 0;
for (i = 1; i <= n; i++)
	for (j = 1; j <= m; j++)
		PS[i][j] = PS[i - 1][j] + PS[i][j - 1] - PS[i - 1][j - 1] + B[i][j];
// O(N^2 * M^2)

// 2、把二维转换为一维 O（N * M * min(N, M))
int MaxSum(int *A, int n, int m) {
	maximum = -INF;
	for (a = 1; a <= n; a++)
		for (c = a; c <= n; c++) {
			Start = BC(a, c, m); // 计算 a和c行 之间的第m列的所有元素之和
			All = BC(a, c, m);
			for (i = m - 1; i >= 1; i--) {
				if (Start < 0)
					Start = 0;
				Start += BC(a, c, i);
				if (Start > All)
					All = Start;
			}
			if (All > maximum)
				maximum = All;
		}
	return maximum;
}