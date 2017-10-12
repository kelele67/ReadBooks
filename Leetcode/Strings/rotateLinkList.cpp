// 1-2-3-4-5-nullptr k=2 4-5-1-2-3-nullptr
class Solution {
public:
    ListNode *rotateLinkList(ListNode *head, int k) {
        if (head == nullptr || k == 0) return head;
        
        int len = 1;
        ListNode *cur = head;
        while (cur->next != nullptr) {
            len++;
            cur = cur->next;
        }
        k = len - k % len;
        // make it a circle
        cur->next = head;
        for (int i = 0; i < k; i++) {
            cur = cur->next;
        }
        // cut it from the kth
        head = cur->next;
        cur->next = nullptr;
        return head;   
    }
};