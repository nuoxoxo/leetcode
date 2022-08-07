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
        if (!head || !(head->next)) return head;

        ListNode*   p;
        int         tmp ;
        bool        foo ;

        foo = false ;
        p = head;
        while (!foo)
        {
            foo = true;
            p = head ;
            while (p->next)
            {
                if (p->val > p->next->val)
                {
                    tmp = p->val;
                    p->val = p->next->val;
                    p->next->val = tmp;
                    foo = false ;
                }
                p = p->next ;
            }
        }
        return head ;
    }
};
