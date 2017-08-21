// 1、利用快排思想 N * log2K
Ktop(S, k):
	if(k <= 0):
		return []
	if(length S <= k):
		return S
	(Sa, Sb) = Partition(S)
	return Ktop(Sa, k).append(Ktop(Sb, k - length Sa))

Partition(S):
	Sa = []
	Sb = []

P = S[1]
	for i in [2 : length S]:
		S[i] > p ? Sa.append(S[i]) : Sb.append(S[i])

length Sa < length Sb ? Sa.append(S[i])
return (Sa, Sb)

// 2、二分查找，f(arr, N, Vmid)返回数组中大于等于Vmid的个数
while (Vmax - Vmin > delta) {
	Vmid = Vmin + (Vmax - Vmin) * 0.5;
	if (f(arr, N, Vmid) >= K) {
		Vmin = Vmid;
	}
	else {
		Vmax = Vmid;
	}
}
// 3、如果N很大，不能放入内存，用最小堆
if (X > h[0]) {
	h[0] = X;
	p = 0;
	while (p < K) {
		q = 2 * p  + 1;
		if (q >= K)
			break;
		if ((q < K - 1) && (h[q+1] < h[q]))
			q = q + 1;
		if (h[q] < h[p]) {
			t = h[p];
			h[p] = h[q];
			h[q] = t;
			p = q;
		}
		else {
			break;
		}
	}
}
// 4、如果N个数都是正整数，并且范围不大，可以记录整数出现的次数
for (sumCount = 0; v = MAXN - 1; v >= 0; v--) {
	sumCount += count[v];
	if (sumCount >= K)
		break;
}
return v;