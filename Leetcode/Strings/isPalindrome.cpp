bool isPalindrome(const char *s, int n) {
	if (s == NULL || n < 1) {
		return false;
	}

	char *front, *back;

	front = s;
	back = s + n - 1;
	while (front < back) {
		if (*front != *back) {
			return false;
		}
		++front;
		--back;
	}
	return true;
}
