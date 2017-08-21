// V ->容量
// C ->可能的最大数量
// H ->满意度
// B ->实际购买量
// OPT ->总量为V的方案中满意度之和的最大值
int Cal(int V, int type) {
	opt[0][T] = 0;
	// 边界条件
	for (int i = 1; i <= V; i++) {
		opt[i][T] = -INF;
	}
	for (int j = T - 1; j >= 0; j--) {
		for (int i = 0; i <= V; i++) {
			opt[i][j] = -INF;
			for (int k = 0; k <= C[j]; k++) {
				if (i <= k * V[j]) {
					break;
				}
				int x = opt[i - k * V[j]][j + 1];
				if (x != -INF) {
					x += H[j] * k;
					if (x > opt[i][j]) {
						opt[i][j] = x;
					}
				}
			}
		}
	}
	return opt[V][0];
}