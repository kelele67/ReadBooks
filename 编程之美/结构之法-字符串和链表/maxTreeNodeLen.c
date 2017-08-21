// 1、相距最远的两个节点一定是叶子节点
// 因为只有两种可能，经过root和不经过root
// 所以可以用动态规划 转化为在子树上的解
// max{d(u1, v1), ... , d(uk, vk), max1 + max2 + 2}
// 深度优先搜索 O(|E|) = O(|V| - 1) E-边的集合，V-点的集合

struct NODE {
	NODE *pLeft;
	NODE *pRight;
	int nMaxLeft;
	int nMaxRight;
	char chValue;
}

int nMaxLen = 0;

void FindMaxLen(NODE *pRoot) {
	if (pRoot == NULL)
		return;

	if (pRoot->pLeft == NULL)
		pRoot->nMaxLeft = 0;
	if (pRoot->pRight == NULL)
		pRoot->nMaxRight = 0;

	if (pRoot->pLeft != NULL)
		FindMaxLen(pRoot->pLeft);
	if (pRoot->pRight != NULL)
		FindMaxLen(pRoot->pRight);

	// 计算左子树最长节点距离
	if (pRoot->pLeft != NULL) {
		int nTempMax = 0;
		if (pRoot->pLeft->nMaxLeft > pRoot->pLeft->nMaxRight) {
			nTempMax = pRoot->pLeft->nMaxLeft;
		}
		else {
			nTempMax = pRoot->pLeft->nMaxRight;
		}
		pRoot->nMaxLeft = nTempMax + 1;
	}

	// 计算右子树最长节点距离
	if (pRoot->pRight != NULL) {
		int nTempMax = 0;
		if (pRoot->pRight->nMaxLeft > pRoot->pRight->nMaxRight) {
			nTempMax = pRoot->pRight->nMaxLeft;
		}
		else {
			nTempMax = pRoot->pRight->nMaxRight;
		}
		pRoot->nMaxRight = nTempMax + 1;
	}

	// 更新最长距离
	if (pRoot->nMaxLeft + pRoot->nMaxRight > nMaxLen)
		nMaxLen = pRoot->nMaxLeft + pRoot->nMaxRight;
}