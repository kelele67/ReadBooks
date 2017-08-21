// 正整数数组, 怎么分成两个数组，和最近
//1、排序，奇书，偶数分别两个数组
//找出一对数字交换，使得和最接近

//2、动态规划 O(4^N)
//2N步，第K步的定义是 前K个元素中任意i个元素的和，所有可能的取值集合为Sk（只考虑小于SUM/2的情况）
//然后把第K步分成两个小步，即首先得到前K-1个元素中，任意i个元素，总共有多少取值-> Sk-1 = {Vi};
//第二步就是令Sk = Sk-1 并 {vi + arr[k]}
//
//Heap[i]表示存储从arr中取i个数能产生的和的集合的堆
for (k = 1; k <= 2 * n; k++) {
	i_max = min(k - 1, n - 1);
	for (i = i_max; i >= 0; i--) {
		for each V in Heap[i]
			insert(v + arr[k], Heap[i + 1])
	}
}

// 3、解法二是根据 Sk-1 = {Vi} -->> Sk
// Sk -->> v, arr[k]  v - arr[k] 是否在Sk-1 = {Vi} 中
// isOK[i][v]表示是否可以找到i个数，使得它们之和等于v
// O(N^2 * Sum)
isOK[0][0] = true;
isOK[i][v] = false(i > 0, v > 0)
for (k = 1; k <= 2 * n; k++) {
	for (i = 1; (i <= k && i <= n); i++)
		for (v = 1; v <= Sum / 2; v++)
			if (v >= arr[k] && isOK[i - 1][v - arr[k]])
				isOK[i][v] = true;
}