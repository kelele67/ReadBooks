// delete two diff ID
Type Find(Type *ID, int N) {
	Type candidate;
	int nTimes, i;
	for (i = nTimes = 0; i < N; i++) {
		if (nTimes == 0) {
			candidate = ID[i], nTimes = 1;
		}
		else {
			if (candidate == ID[i]) {
				nTimes++;
			}
			else {
				nTimes--;
			}
		}
	}
	return candidate;
}