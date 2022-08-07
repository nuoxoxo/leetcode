class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode    *fast, *slow;

        if (!head)
            return head ;
        fast = head->next;
        slow = head ;
        while (fast)
        {
            if (slow->val ^ fast->val)
            {
                slow->next = fast;
                slow = slow->next;
                fast = fast->next;
            }
            else
                fast = fast->next;
        }
        slow->next = fast;
        return head ;
    }
};
