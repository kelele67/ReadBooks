void reverseList(ListNode *head) {
    if (head == nullptr) {
        return;
    }

    if (head->next != nullptr) {
        reverse(head->next);
    }
    cout << head->data << "\t";
}