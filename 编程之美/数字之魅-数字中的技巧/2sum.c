// 1、暴力穷举

// 2、hash表

// 3、先排序，然后二分 O(N)
for (i = 0, j = n - 1; i < j; ) {
	if (arr[i] + arr[j] == Sum)
		return (i, j);
	else if (arr[i] + arr[j] < Sum)
		i++;
	else
		j--;
}
return (-1, -1);