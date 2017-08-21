// 不需要连续的递增子序列
// 1、直接法 O(N^2)
int LIS(int[] array) {
	int[] LIS = new int[array.Length];
	for (int i = 0; i < array.Length; i++) {
		LIS[i] = 1;
		for (int j = 0; j < i; j++) {
			if (array[i] > array[j] && LIS[j] + 1 > LIS[i]) {
				LIS[i] = LIS[j] + 1;
			}
		}
	}
	return Max(LIS);
}

// 2、改进
// 希望找到前i个元素中的一个递增子列，使得这个递增子序列的最大的元素比 array[i+1]小，且长度尽量长
// 仍然是穷举遍历-> O(N^2)
int LIS(int[] array) {
	// 记录数组中的递增序列信息
	int [] MaxV = new int[array.Length + 1];

	MaxV[1] = array[0]; // 数组中第一值，边界值
	MaxV[0] = Min(array) - 1; // 数组中最小值，边界值
	int [] LIS = new int[array.Length];

	for (int i = 0; i < LIS.Length; i++) {
		LIS[i] = 1;
	}

	int nMaxLIS = 1; // 数组最长递增子序列的长度

	for (int i = 1; i < array.Length; i++) {
		int j;
		for (j = nMaxLIS; j >= 0; j--) {
			if (array[i] > MaxV[j]) {
				LIS[i] = j + 1;
				break;
			}
		}

		if (LIS[i] > nMaxLIS) {
			nMaxLIS = LIS[i];
			MaxV[LIS[i]] = array[i];
		}
		else if (MaxV[j] < array[i] && array[i] < MaxV[j + 1]) {
			MaxV[j + 1] = array[i];
		}
	}
	return nMaxLIS;
}

// 3、对穷举部分进行修改
for (j = LIS[i - 1]; j >= 1; j--) {
	if (array[i] > maxv[j]) {
		LIS[i] = j + 1;
		break;
	}
}
// 如果把上述的查询部分利用二分查找进行加速-> O(N * log2N)