class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode    *temp;
        ListNode    *p;
        
        while (head && head->val == val)
        {
            temp = head;
            head = head->next;
            temp->next = NULL;  // still AC w/o this line
        }
        p = head;
        while (p && p->next)
        {
            if (p->next->val == val)
            {
                temp = p->next;
                p->next = p->next->next;
                temp->next = NULL; // still AC w/o this line
            }
            else    p = p->next;
        }
        return (head);
    }
};
