class Solution
{
public:
	Listnode* mergeTwoLists(Listnode*l1, Listnode*l2){
		if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;
		Listnode dummy(-1);
		Listnode *p = &dummy;
		for(; l1 != nullptr && l2 != nullptr; p = p->next){
			if (l1->val > l2->val){
				p->next = l2;
				l2 = l2->next;
			}
			else{
				p->next = l1;
				l1 = l1->next;
			}
		}
		p->next = l1 != nullptr ? l1 : l2;
		return dummy.next;
	}
	
};