class Solution {
public:
	ListNode	*oddEvenList(ListNode* head)
	{
		ListNode	*odd;
		ListNode	*eve;
		ListNode	*head_eve;

		if (!head)		return (NULL);
		if (!(head->next))	return (head);
		odd = head;
		head_eve = head->next;
		eve = head->next;
		while (odd->next && eve->next)
		{
			odd->next = eve->next;
			eve->next = odd->next->next;
			odd = odd->next;
			eve = eve->next;
		}
		odd->next = head_eve;

		return (head);
	}
};
