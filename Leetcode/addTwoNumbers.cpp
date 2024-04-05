#include "addTwoNumbers.h"

ListNode* addTwoNumbers::addTwoNumberstw(ListNode* l1, ListNode* l2)
{
	int c = 0;
	ListNode newHead(0);
	ListNode* t = &newHead;
	while (c || l1 || l2)
	{
		int f = 0;

		if (l1) {
			f += l1->val;
		}
		else {
			f += 0;
		}
		if (l2) {
			f += l2->val;
		}
		else {
			f += 0;
		}

		c += f;

		t->next = new ListNode(c % 10);
		t = t->next;
		c /= 10;

		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}
	return newHead.next;
}
