// 辗转相除法
int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x%y);
}

// 改进大整数的取模运算
// f(x, y) = f(x - y, y)
BigInt gcd(BigInt x, BigInt y) {
	if (x < y)
		return gcd(y, x);
	if (y == 0)
		return x;
	else
		return gcd(x - y, y);
}

// 用移位运算和减法运算，避开了大整数除法
// 用2这个素数进行移位运算，
// x, y 都为偶数 f(x, y) = 2 * f(x/2, x/2) = 2 * f(x >> 1, y >> 1)
// x偶数，y奇数  f(x, y) = f(x/2, y) = f(x >> 1, y)
// x奇数，y偶数  f(x, y) = f(x, x/2) = f(x, y >> 1)
// x, y 都奇数  f(x, y) = f(x, x - y)
// 最坏时间复杂度为 log2 (max(x, y))
BigInt gcd(BigInt x, BigInt y) {
	if (x < y)
		return gcd(y, x)
	if (y == 0)
		return x;
	else
		// 是否为偶数
		if (IsEven(x)) {
			if (IsEven(y))
				return (gcd(x >> 1, y >> 1) << 1);
			else
				return gcd(x >> 1, y);
		}
		else {
			if (IsEven(y))
				return gcd(x, y >> 1);
			else
				return gcd(y, x - y);
		}
}