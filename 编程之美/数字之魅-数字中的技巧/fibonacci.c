int Fibonacci(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

//求解通项公式
//F(n) = F(n-1) + F(n-2)
//x^2 = x + 1
// x = [ 1+- sqrt(5) ] / 2
// F(n) = (sqrt(5) / 5) * (x)^n - (sqrt(5) / 5) * (-x(负号))^n
// 引入了无理数，不能保证结果的精度

// 3、幂矩阵
// (Fn Fn-1) = (Fn-1 Fn-2) * A (1)
// A = (1 1)
//     (1 0)
// 由(1)得 -> (Fn Fn-1) = (Fn-1 Fn-2) * A = (Fn-2 Fn-3) * A^2 = ... = (F1 F0) * A^n-1
// 然后求解矩阵A的方幂
// An = A * A *...* A
// A^x+y = A^x * A^y
// A^x*2 = A^x+x = (A^x)^2
// 用二进制表示n
// n = ak * 2^k + ak-1 * 2^k-1 + ... + a1 * 2 + a0
// A^n = A^(ak * 2^k + ak-1 * 2^k-1 + ... + a1 * 2 + a0)
// = (A^(2^k))^a1 * (A^(2^k-1))^ak-1 * .. * (A^(2^1))^a1 * A^a0
// 如果能够得到A^(2^i)的值，就可以再经过log2n次乘法得到A^n
// 递推得 A^(2^i) = (A(2^i-1))^2
class Matrix;
// 实现了乘法操作的矩阵类
// 求解m的n次方
Matrix MatrixPow(const Matrix& m, int n) {
	Matrix result = Matrix::Identity;
	Matrix tmp = m;
	for (; n; n >>= 1) {
		if (n & 1)
			result *= tmp;
		tmp *= tmp;
	}
}
int Fibonacci(int n) {
	Matrix an = MatrixPow(A, n-1);
	return F1 * an(0, 0) + F0 * an(1, 0);
}
// log2n