int biSearch(char **arr, int b, int e, char *v) {
	int minIndex = b, maxIndex = e, midIndex;

	while (minIndex < maxIndex - 1) {
		midIndex = (minIndex + (maxIndex - minIndex)) / 2;
		if (strcmp(arr[midIndex], v) <= 0) {
			minIndex = midIndex;
		}
		else {
			maxIndex = midIndex;
		}
		if (!strcmp(arr[maxIndex], v)) {
			return maxIndex;
		}
		else if (!strcmp(arr[minIndex], v)) {
			return minIndex;
		}
		else {
			return -1;
		}
	}
}