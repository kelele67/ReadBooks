// baoli
for (M = 2; ; M++) {
	product = N * M;
	if (HasOnlyOneAndZero(product))
		output N, M, product, and return;
}

// 求 X 的十进制表示形式中只含有1 和 0， 并且X 被 N整数
// BigInt[i]表示模N等于i的十进制表示中只含1和0的最小整数，
// 但是我们只需要记下1的位置即可
// 即BigInt的每个元素是一个变长数组，
// 对于模N等于i的最小X，BigInt的每个元素将存储最小X在十进制中表示“1”的位置
// init
for (i = 0; i < N; i++)
	BigInt[i].clear();
BigInt[1].push_back(0);

for (i = 1, j = 10 % N; ; i++, j = (j * 10) % N) {
	int NoUpdate = 0;
	bool flag = false;
	if (BigInt[j].size() == 0) {
		// BigInt[j] = 10 ^ i, (10 ^i % N = j)
		BigInt[j].clear();
		BigInt[j].push_back(i);
	}
	for (k = 1; k < N; k++) {
		if ((BigInt[k].size() > 0)
			&& (i > BigInt[k][BigInt[k].size() - 1])
			&& (BigInt[(k + j) % N].size() == 0)) {
			// BigInt[(k + j) % N] = 10^i + BigInt[k]
			flag = true;
			BigInt[(k + j) % N] = BigInt[k];
			BigInt[(k + j) % N].push_back(i);
		}
	}
	if (flag == false)
		NoUpdate++;
	// 如果没能更新，无解
	// 如果找到解，跳出
	if (NoUpdate == N || BigInt[0].size() > 0)
		break;
}
if (BigInt[0].size() == 0) {
	//M not exist
}
else {
	Find N * M = BigInt[0]
}