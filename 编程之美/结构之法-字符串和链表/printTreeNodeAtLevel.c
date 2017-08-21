// 打印某一层
// 1、普通递归
struct Node {
	int data;
	Node* lChild;
	Node* rChild;
}
int printNodeAtLevel(Node* root, int level) {
	if (!root || level < 0)
		return 0;
	if (level == 0) {
		cout << root->data << " ";
		return 1;
	}
	return printNodeAtLevel(node->lChild, level - 1) + printNodeAtLevel(node->rChild, level-1)
}

// 2、如果知道了二叉树的深度
void printNodeAtLevel(Node* root, int depth) {
	for (int level = 0; level < depth; level++) {
		printNodeAtLevel(root, level);
		cout << endl;
	}
}

// 如果不知道，则先求二叉树的深度
int GetDepth(Node *root) {
	if (root == NULL)
		return 0;
	return GetDepth(root->lChild) > GetDepth(root->rChild) ? (GetDepth(root->lChild) + 1) : (GetDepth(root->rChild) + 1)
}

//非递归版
struct denode {
	Node *node;
	int depth;
}
int maxDepth(Node *root) {
	if (root == NULL)
		return 0;

	queue<denode> que;

	denode dnode;
	dnode.depth = 1;
	dnode.node = root;

	que.push(dnode);

	int depth = 1;
	while (!que.empty()) {
		denode ptr = que.front();
		que.pop();

		depth = ptr.depth;

		if (ptr.node->lChild != NULL) {
			denode p;
			p.node = ptr.node->lChild;
			p.depth = ptr.depth + 1;
			que.push(p);
		}

		if (ptr.node->rChild != NULL) {
			denode p;
			p.node = ptr.node->rChild;
			p.depth = ptr.depth + 1;
			que.push(p);
		}
	}
	return depth;
}

// 附上 求二叉树宽度
int GetWidth(BTNode *pRoot)  
{  
    if (pRoot == NULL)  
    {  
        return 0;  
    }  
  
    int nLastLevelWidth = 0;//记录上一层的宽度  
    int nTempLastLevelWidth = 0;  
    int nCurLevelWidth = 0;//记录当前层的宽度  
    int nWidth = 1;//二叉树的宽度  
        queue<BTNode *> myQueue;  
    myQueue.push(pRoot);//将根节点入队列  
    nLastLevelWidth = 1;      
    BTNode *pCur = NULL;  
  
    while (!myQueue.empty())//队列不空  
    {  
        nTempLastLevelWidth = nLastLevelWidth;  
        while (nTempLastLevelWidth != 0)  
        {  
            pCur = myQueue.front();//取出队列头元素  
            myQueue.pop();//将队列头元素出对  
  
            if (pCur->m_left != NULL)  
            {  
                myQueue.push(pCur->m_left);  
            }  
  
            if (pCur->m_right != NULL)  
            {  
                myQueue.push(pCur->m_right);  
            }  
  
            nTempLastLevelWidth--;  
        }  
  
        nCurLevelWidth = myQueue.size();  
        nWidth = nCurLevelWidth > nWidth ? nCurLevelWidth : nWidth;  
        nLastLevelWidth = nCurLevelWidth;  
    }  
  
    return nWidth;  
}

// 层次遍历二叉树
// 不求二叉树的深度
void printNodeByLevel(Node *root) {
	for (int level = 0; ; level++) {
		if (!printNodeAtLevel(root, level))
			break;
		cout << endl;
	}
}

// 然而，每一层的访问都要重新从根节点开始，直到访问完所有的层次
// 改进
// 把每一层的节点都压入数组，并且找到这一层最后一个节点用LAST指针指向->利用vector的动态扩充
void printNodeByLevel(Node *root) {
	if (root == NULL)
		return;
	vector<Node*> vec;

	vec.push_back(root);
	int cur = 0;
	int last = 1;
	while (cur < vec.size()) {
		last = vec.size();

		while (cur < last) {
			cout << vec[cur]->data << " ";
			if (!vec[cur]->lChild)
				vec.push_back(vec[cur]->lChild);
			if (!vec[cur]->rChild)
				vec.push_back(vec[cur]->rChild);
			cur++;
		}
		cout << endl;
	}
}