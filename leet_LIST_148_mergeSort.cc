/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        ListNode    *midpoint, *L, *R;

        if (!head || !(head->next)) return head ;
        L = head;
        midpoint = findMiddleNode(head);
        R = midpoint->next;
        midpoint->next = NULL ;
        L = sortList(L);
        R = sortList(R);

        return mergeSort(L, R) ;
    }

    ListNode* mergeSort(ListNode *p, ListNode *q)
    {
        ListNode    *ghost, *cur;

        ghost = new ListNode(0);
        cur = ghost;
        while (p && q)
        {
            if (p->val < q->val)
            {
                cur->next = p;
                p = p->next;
            }
            else
            {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next ;
        }
        if (p)  cur->next = p;
        if (q)  cur->next = q;
        return (ghost->next) ;
    }

    ListNode* findMiddleNode(ListNode *p)
    {
        ListNode    *rabbit, *turtle;

        if (!p || !(p->next))   return p ;
        rabbit = p->next;
        turtle = p ;
        while (rabbit && rabbit->next)
        {
            rabbit = rabbit->next->next;
            turtle = turtle->next ;
        }
        return (turtle);
    }
};
