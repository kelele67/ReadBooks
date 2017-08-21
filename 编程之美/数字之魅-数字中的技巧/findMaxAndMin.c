// 1、2* N次比较

// 2、N/2 次比较->大的数字放偶数位，小的放奇数位
// N/2 * 2 分别找到最大数最小数

// 3、如果不能破坏原数组
// 那就遍历的时候记录下MAX MIN，不断更新


// 4、分治法
// 前后N/2个数的MIN 和 MAX
(max, min) Search(arr, b, e) {
	if (e - b <= 1) {
		if (arr[b] < arr[e])
			return (arr[e], arr[b]);
		else
			return (arr[b], arr[e]);
	}
	(maxL, minL) = Search(arr, b, b + (e - b) / 2);
	(maxR, minR) = Search(arr, b + (e - b) / 2 + 1, e);
	if (maxL > maxR)
		maxV = maxL;
	else
		maxV = maxR;
	if (minL < minR)
		minV = minL;
	else
		minV = minR;
	return (maxV, minV);
}
// 比较次数为 1.5N - 2