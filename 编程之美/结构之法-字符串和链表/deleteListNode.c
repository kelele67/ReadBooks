// 1、O(1)
void DeleteRandomNode(node* pCurrent) {
	Assert(pCurrent != NULL);
	node *pNext = pCurrent->next;
	if (pNext != NULL) {
		pCurrent->next = pNext->next;
		pCurrent->data = pNext->data;
		delete pNext;
	}
}

// 但是得考虑是不是尾指针

// 2、用Linus的二级指针法
typedef bool (*remove_fn) (node const *v);
void remove_if(node ** head, remove_fn rm) {
	for (node ** curr = head; *curr; ) {
		node *entry = *curr; // entry保存了*curr，意味着下一次循环，entry就是prev->next指针所指向的内存
		if (rm(entry)) {
			*curr = entry->next; //删除结点，于是，prev->next指向了entry->next
			free(entry);
		}
		else {
			curr = &entry->next; // 如果不删除当前结点，curr保存的是当前结点next指针的地址
		}
	}
}

// 用通俗语言解释下我的理解
// 二级指针：指向next指针->next指针->next本身
// 首先是二级指针的头结点定义为curr，当*curr也就是指针还存在时，循环
// 定义一个入口entry，为*curr也就是指向下一个节点的指针
// 如果删除的是下一个节点，*curr也就是next指针，指向entry->next下一个节点，然后free掉entry
// 如果删除的不是下一个节点，curr即next本身，变成下一个节点的next，即把entry->next的地址赋值给curr