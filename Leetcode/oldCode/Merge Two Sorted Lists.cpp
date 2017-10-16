/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//维护一个新的链表，用两个指针指向两个链表，类似merge sot的比较。
//对于第一个node需要update的情形（即linked list可能空的），
//一般可以使用dummy node来避免使用if来分情况讨论，
//具体方法就是建立一个dummy node使得它next指向linked list的第一个node,
//但是需要注意的是此时函数返回值必须为Node *即pointer to Node.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (l1 == nullptr) return l2;
    	if (l2 == nullptr) return l1;
    	ListNode dummy(-1);
    	ListNode *p = &dummy;
    	for (; l1 != nullptr && l2 != nullptr; p = p->next){
    		if (l1->val > l2->val){
    			p->next = l2;
    			l2 = l2->next;
    		}
    		else{
    			p->next = l1;
    			l1 = l1->next;
    		}
    	p->next = l1!= nullptr ? l1 : l2;
    	return dummy.next;
    	}
        
    }
};