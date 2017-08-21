int count(int v) {
	int count = 0;
	while (v) {
		v &= (v-1);
		count++;
	}
	return count;
}