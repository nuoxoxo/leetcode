class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode    *fast, *slow, *dumm ;

        if (!head || !(head->next)) return head ;
        dumm = new ListNode();
        slow = dumm ;
        fast = head ;
        while (fast)
        {
            if (fast->next && fast->val == fast->next->val)
                while (fast->next && fast->val == fast->next->val)
                    fast = fast->next ;
            else
            {
                slow->next = fast;
                slow = fast;
            }
            fast = fast->next ;
        }
        slow->next = NULL ;

        return dumm->next ;
    }
};
