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
    struct ListNode    *ghost, *cur, *res;

    if (!(ghost = (struct ListNode*) malloc(sizeof(struct ListNode))))
	    return NULL ;
    ghost->next = NULL ;
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
    res = ghost->next;
    free(ghost) ;
    return (res) ;
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
