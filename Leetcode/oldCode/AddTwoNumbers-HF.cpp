class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		//定义一个假的头结点
		ListNode dummy(-1);
		ListNode *prev = &dummy;
		int carry = 0;
		//对两个链表进行循环
		for (ListNode *pa = l1, *pb = l2; 
			pa !=nullptr || pb !=nullptr;
			pa = pa == nullptr ? nullptr : pa->next,
			pb = pb == nullptr ? nullptr : pb->next, prev = prev->next) {
			const int ai = pa == nullptr ? 0 : pa->val;
			const int bi = pb == nullptr ? 0 : pb->val;
			const int value = (ai + bi + carry) % 10;
		    carry = (carry + ai + bi) / 10;
		    //尾插法
		    prev->next = new ListNode(value);
		}
		//循环完毕，任然要进位，则添加新的结点
		if (carry > 0) {
			prev->next = new ListNode(carry);
		}
		return dummy.next;
	}
};