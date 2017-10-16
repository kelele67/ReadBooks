class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1); //头结点（假的），是一个局部变量
		int carry = 0;
		ListNode *prev = &dummy;
		for (ListNode *pa = l1, *pb = 12;
			pa != nullptr || pb != nullptr;
			pa = pa == nullptr ? nullptr : pa->next,
			pb = pb == nullptr ? nullptr : pb->next,
			prev = prev->next) {
			const int ai = pa == nullptr ? 0 : pa->val;
		    const int bi = pb == nullptr ? 0 : pb->val;
		    const int value = (ai + bi +carry) % 10;
		    carry = (ai + bi +carry) / 10;
		    prev->next = new ListNode(value); //尾插法
		}
		if (carry > 0)
			prev->next = new ListNode(carry);
		return dummy.next;

	}
};