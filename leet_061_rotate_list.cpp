class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head)
            return head ;

        ListNode    *tail, *piv, *res;
        int         n, i;

        n = 1;
        tail = head ;
        while (tail->next)
        {
            tail = tail->next;
            ++n;
        }
        k %= n;
        if (!k)
            return head ;
        piv = head ;
        i = -1;
        while (++i < n - k - 1)
            piv = piv->next;
        res = piv->next;
        piv->next = NULL;
        tail->next = head;

        return res ;
    }
};
