class Solution {
public:
	bool IsLoop(ListNode *head) {
		ListNode *slow = head, *fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) {
				break;
			}
		}

		return !(fast == NULL || fast->next == NULL);
	}
};
