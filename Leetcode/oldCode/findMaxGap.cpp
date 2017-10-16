class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		int max = A[0], min;
		for (int i = 0; i < n; i ++) {
			if (A[i] > max) {
				max = A[i];
			}
			min = A[0] > A[n - 1] ? A[n - 1]:A[0];
		}
		return max - min;
	}
};