class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode    *fast, *slow;

        if (!head)
            return NULL ;
        fast = slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                slow = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL ;
    }
};
