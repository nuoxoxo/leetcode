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

struct ListNode* mergeSort(struct ListNode*, struct ListNode*);
struct ListNode* findMiddleNode(struct ListNode*);

struct ListNode* sortList(struct ListNode* head)
{
    struct ListNode    *midpoint, *L, *R;

    if (!head || !(head->next)) return head ;
    L = head;
    midpoint = findMiddleNode(head);
    R = midpoint->next;
    midpoint->next = NULL ;
    L = sortList(L);
    R = sortList(R);

    return mergeSort(L, R) ;
}

struct ListNode* mergeSort(struct ListNode *p, struct ListNode *q)
{
    struct ListNode    *x, *y, *L, *R;

    if (!p && !q)   return NULL ;
    if (p && !q)    return p ;
    if (q && !p)    return q ;
    x = p;
    y = q;
    if (x->val < y->val)
    {
        L = R = x;
        x = x->next;
    }
    else
    {
        L = R = y;
        y = y->next;
    }
    while (x && y)
    {
        if (x->val < y->val)
        {
            R->next = x;
            x = x->next;
            R = R->next;
        }
        else
        {
            R->next = y;
            y = y->next;
            R = R->next;
        }
    }
    while (x)
    {
        R->next = x;
        x = x->next;
        R = R->next;
    }
    while (y)
    {
        R->next = y;
        y = y->next;
        R = R->next;
    }
    R->next = NULL ;
    return L ;
}

struct ListNode* findMiddleNode(struct ListNode *p)
{
    struct ListNode    *rabbit, *turtle;

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
