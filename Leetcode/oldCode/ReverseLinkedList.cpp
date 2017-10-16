/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//能加const的地方一定加const
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		//链表为空
		//...
		//不为空时
		ListNode dummy(-1);
		dummy.next = head;

		ListNode *prve = &dummy;
		//将prev指向m的前一个结点作为头结点（组成头部23333）
		for (int i = 0; i < m -1; ++i) {
			prve = prve->next;
		}
		ListNode *const head2 = prve;

		//cur表示要插入的那个，m后面一个就是第一个要插入的
		prve = head2->next;
		ListNode *cur = prve->next;

		//头插法完成reverse
		for (int i = m; i < n; i++) {
			//拿出cur
			prve->next = cur->next;
			//头插法
			cur->next = head2->next;
			head2->next = cur;
			//下一个要插入的元素发生改变
			cur = prve->next;
		}
		return dummy.next;
	}
};