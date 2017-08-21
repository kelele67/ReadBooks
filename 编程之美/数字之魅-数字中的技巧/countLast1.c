// N!含有质因数2的个数， 等于 N/2 + N/4 + N/8 + N/16 + ...,
int lowestOne(int N) {
	int ret = 0;
	while (N) {
		N >>= 1;
		ret += N;
	}
	return ret;
}

// N!含有质因数2的个数，还等于N减去N的二进制表示中1的数目
// N/k 等于1，2，3，。。。N中能被k整除的个数
int lowestOne(int N) {
	int ret = 0;
	while (N) {
		N >> 1;
		ret += N;
	}
	return ret;
}