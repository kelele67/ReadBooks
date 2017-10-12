
bool isPalindromeLinkList(ListNode *head) {
	ListNode *fast = head;
	ListNode *low = head;

	while (fast->next == nullptr) {
		fast = fast->next->next;
		low = low->next;
	}
	ListNode *mid = low;
	reverseList(low);

	while (mid->next != nullptr) {
		if (*head != *mid) {
			return false;
		}
		head = head->next;
		mid = mid->next;
	}
	return true;
}

ListNode *reverseList(ListNode *head) {
	ListNode dummy(-1);
	dummy.next = head;
	ListNode *prev = *dummy;
	ListNode *cur = prev->next;

	while (cur->next != nullptr) {
		prev->next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = prev->next;
	}
	return dummy.next;
}

