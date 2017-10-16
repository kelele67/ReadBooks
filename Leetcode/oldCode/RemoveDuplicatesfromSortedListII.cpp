class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr) return head;

		ListNode dummy(INT_MIN);
		dummy.next = head;
		ListNode *prev = &dummy, *cur = head;
		while (cur != nullptr) {
			bool duplicated = false;
			while(cur->next != nullptr && cur->val == cur->next->val) {
				duplicated = true;
				ListNode *temp = cur;
				cur = cur->next;
				delete temp;
			}
			if (duplicated) {//删除重复的最后一个元素
				ListNode *temp = cur;
				cur = cur->next;
				delete temp;
				continue;
			}
			//在删除节点之后保证链表不被断开，连接到当前节点
			prev->next = cur;
			//前驱往后移动
			prev = prev->next;
			//当前节点往后移动
			cur = cur->next;
		}
		//最后cur为空，为链表尾端
		prev->next = cur;
		// prev->next = nullptr;
		return dummy.next;
	}
};