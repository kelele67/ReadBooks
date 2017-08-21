// 连续的子数组求和
 
// 1、暴力法
int MaxSum(int *A, int n) {
	int maximum = -INF;
	int sum;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				sum += A[k];
			}
			if (sum > maximum) {
				maximum = sum;
			}
		}
	}
	return maximum;
}

// 改进后 O(N^2)
int MaxSum(int *A, int n) {
	int maximum = -INF;
	int sum;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			if (sum > maximum)
				maximum = sum;
		}
	}
	return maximum;
}

// 2、分治法 O(n * log2N)

// 3、分治法的改进->动态规划
// All[1]   -> 最大的一段之和
// Start[1] -> 包含A[1]的和最大的一段之和
// max {A[0], A[0] + Start[1], All[1]}
int max(int x, int y) {
	return (x > y) ? x : y;
}

int MaxSum(int *A, int n) {
	int Start[n - 1] = A[n - 1];
	int All[n - 1] = A[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		Start[i] = max(A[i], A[i] + Start[i + 1]);
		All[i] = max(Start[i], All[i + 1]);
	}
	return All[0];
}
// O(N)

// 4、继续降低空间复杂度
int max(int x, int y) {
	return (x > y) ? x : y;
}

int MaxSum(int *A, int n) {
	int nStart = A[n - 1];
	int nAll = A[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		nStart = max(A[i], nStart + A[i]);
		nAll = max(nStart, nAll);
	}
	return nAll;
}

// 换一种写法
int MaxSum(int *A, int n) {
	int nStart = A[n - 1];
	int nAll = A[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (nStart < 0)
			nStart = 0
		nStart += A[i];
		if (nStart > nAll) {
			nAll = nStart;
		}
	}
	return nAll;
}