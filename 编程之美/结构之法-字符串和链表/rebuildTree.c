struct NODE {
	NODE* pLeft;
	NODE* pRight;
	char chValue;
}

// 有了前序遍历和中序遍历
#define TREELEN 6

void reBuild(char *pPreOrder,
	char * pInOrder,
	int nTreeLen,
	NODE ** pRoot) {
	if (pPreOrder == NULL || pInOrder == NULL)
		return;

	// 获得前序遍历的第一个节点
	NODE* pTemp = new NODE;
	pTemp->chValue = *pPreOrder;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;

	// 如果节点为空，把当前结点复制到根节点
	if(*pRoot == NULL)
		*pRoot = pTemp;

	if (nTreeLen == 1)
		return;

	// 寻找子树长度
	char *pOrgInOrder = pInOrder;
	char *pLeftEnd = pInOrder;
	int nTempLen = 0;

	// 找到左子树的结尾
	while (*pPreOrder != *pLeftEnd) {
		if (pPreOrder == NULL || pLeftEnd == NULL)
			return;
		nTempLen++;

		// 记录临时长度，以免溢出
		if (nTempLen > nTreeLen)
			break;
		pLeftEnd++;
	}

	// 寻找左子树长度
	int nLeftLen = 0;
	nLeftLen = (int)(pLeftEnd - pOrgInOrder);
	// 寻找右子树长度
	int nRightLen = 0;
	nRightLen = nTreeLen - nLeftLen - 1;
	// 重建左子树
	if (nLeftLen > 0)
		reBuild(pPreOrder + 1, pInOrder, nLeftLen, &((*pRoot)->pLeft));
	// 重建右子树
	if (nRightLen > 0) 
		reBuild(pPreOrder + nLeftLen + 1, pInOrder + nLeftLen + 1, nRightLen, 
			&((*pRoot)->pRight));
}

int main() {
	char szPreOrder[TREELEN] = {};
	char szInOrder[TREELEN] = {};

	NODE *pRoot = NULL;
	reBuild(szPreOrder, szInOrder, TREELEN, &pRoot);
}