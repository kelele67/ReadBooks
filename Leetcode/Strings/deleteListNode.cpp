//O(1)
bool deleteNode(ListNode *head, ListNode *p) {
    if (!p || !head) {
        return false;
    }
    //不是尾指针
    if (p->next != nullptr) {
        ListNode *del = p->next;
        p->value = del->value;
        p->next = del->next;
        delete del;
        del = NULL;
    } else if (head == p) {
        //是尾指针，但是只有一个结点
        delete p;
        head = NULL;
    } else {
        //是尾指针，有多个结点
        ListNode *tmp = NULL;
        *pre = head;
        while (pre->next != p) {
            pre = pre->next;
        }
        delete p;
        p = NULL;
        pre->next = NULL;
    }
    return true;
}