// 1、暴力法，判断第一个链表的每个节点是否在第二个链表中 O(lenh1 * lenh2)

// 2、hash表计数法，把第一个链表进行hash排序，O(lenh1 + lenh2)

// 3、转换为是否有环的问题，将第一个链表的结尾接到第二个链表的头，然后遍历第二个链表，
// 看是否有环 O(lenh1 + lenh2)

// 4、遍历一个链表到最后一个节点，然后遍历第二个链表，也到最后一个节点，对比两个节点是否相同
int isCross(node *h1, node *h2) {
	node *p, *q;
	for (p = h1; p->next != NULL; p++);
	for (q = h2; q->next != NULL; q++);

	return p == q ? 1 : 0;
}