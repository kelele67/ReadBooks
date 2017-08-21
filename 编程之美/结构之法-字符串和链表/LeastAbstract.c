int nTargetLen = N + 1;
int pBegin = 0;
int pEnd = 0;
int nLen = N;
int nAbstractBegin = 0;
int nAbstractEnd = 0;

while (true) {
	while (!isAllExisted() && pEnd < pLen) {
		pEnd++;
	}

	while (isAllExisted()) {
		if (pEnd - pBegin < nTargetLen) {
			nTargetLen = pEnd - pBegin;
			nAbstractBegin = pBegin;
			nAbstractEnd = pEnd - 1;
		}
		pBegin++;
	}
	if (pEnd >= N)
		break;
}