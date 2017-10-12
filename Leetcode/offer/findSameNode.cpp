class Solution {
public:
	ListNode *findSameNode(ListNode* head1, ListNode* head2) {
		ListNode *p1 = head1;
		ListNode *p2 = head2;
		for (; p1->next = nullptr; p1 = p1->next) {
			for (; p2->next = nullptr; p2 = p2->next) {
				if (p1 == p2) {
					while (p1->next != nullptr) {
						p1 = p1->next;
					}
					while (p2->next != nullptr) {
						p2 = p2->next;
					}
					if (p1 == p2) {
						return p1;
					}
					else {
						return -1;
					}
				}
			}
		}
	}
};
