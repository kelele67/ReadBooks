class Solution {
public:
	void findNumsAppearOnce(vector<int> data, int* num1, int* num2) {
		if (data.size() < 2) {
			return;
		}

		int size = data.size();
		int temp = 0;
		for (int i = 0; i < size; i++) {
			temp = temp ^ data[i];
		}
		int split = temp & ~(temp - 1);
		for (int i = 0; i < size; i++) {
			if (data[i] & split) {
				*num1 ^= data[i];
			}
			else {
				*num2 ^= data[i];
			}
		}
	}
};
