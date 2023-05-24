class Solution {
public:
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2)
    {
        ListNode    *dumm = new ListNode() ;
        ListNode    *curr = dumm;
        int         carry = 0;

        while (t1 || t2 || carry)
        {
            if (t1)
            {
                carry += t1->val;
                t1 = t1->next ;
            }
            if (t2)
            {
                carry += t2->val;
                t2 = t2->next ;
            }
            curr->next = new ListNode(carry % 10);
            curr = curr->next;
            carry /= 10 ;
        }
        return dumm->next ;
    }
};
