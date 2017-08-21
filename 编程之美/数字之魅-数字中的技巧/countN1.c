long long sum1s(unsigned long long n) {
	unsigned long long iCount = 0;
	unsigned long long iFactor = 1;
	unsigned long long iLowerNum = 0;
	unsigned long long iCurrNum = 0;
	unsigned long long iHigherrNum = 0;

	while (n / iFactor != 0) {
		iLowerNum = n - (n / iFactor) * iFactor;
		iCurrNum = (n / iFactor) % 10;
		iHigherrNum = n / (iFactor * 10);

		switch(iCurrNum) {
			case 0:
				iCount += iHigherrNum *iFactor;
				break;
			case 1:
				iCount += iHigherrNum * iFactor + iLowerNum + 1;
				break;
			default:
				iCount += (iHigherrNum + 1) *iFactor;
				break;
		}
		iFactor *= 10;
	}
	return iCount;
}