class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B;
		int size = A.size();
		if (size == 0) {
			return B;
		}
		B.push_back(1);
		for (int i = 0; i < size - 1; i++) {
			B.push_back(B.back() * A[i]);
		}
		int temp = 1;
		for (int i = size - 2; i >= 0;i--) {
			temp *= A[i + 1];
			B[i] *= temp;
		}
		return B;
	}
};
