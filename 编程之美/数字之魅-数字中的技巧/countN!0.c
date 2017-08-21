// count 5, then sum
ret = 0;
for (i = 1; i < N; i++) {
	j = i;
	while (j % 5 == 0) {
		ret++;
		j /= 5;
	}
}

ret = 0;
while (N) {
	ret += N / 5;
	N /= 5;
}