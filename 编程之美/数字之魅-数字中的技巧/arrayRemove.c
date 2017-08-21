// N 个元素数组右移K位. O(N)
// 1、不合要求 O(K * N)
RightShift(int *arr, int N, int K) {
	while (K--) {
		int t = arr[N-1];
		for (int i = N - 1; i > 0; i --)
			arr[i] = arr[i - 1];
		arr[0] = t;
	}
}

// 右移K = 右移 K % N  O(N^2)
RightShift(int *arr, int N, int K) {
	K %= N;
	while (K--) {
		int t = arr[N-1];
		for (int i = N - 1; i > 0; i--)
			arr[i] = arr[i-1];
		arr[0] = t;
	}
}

Reverse(int *arr, int b, int e) {
	for (; b < e; b++, e--) {
		int temp = arr[e];
		arr[e] = arr[b];
		arr[b] = temp;
	}
}

RightShift(int *arr, int N, int k) {
	K %= N;
	Reverse(arr, 0, N - K - 1);
	Reverse(arr, N - K, N - 1);
	Reverse(arr, 0, N - 1);
}