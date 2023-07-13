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
    ListNode* middleNode(ListNode* head)
    {
        map<int, ListNode*> mp;
        ListNode            *p;
        int                 i;

        if (!head)
		return (NULL);
        p = head;
        i = 0;
        while (p)
        {
            ListNode *temp;
            temp = p;
            mp[i] = temp;
            p = p->next;
            i++;
        }
        return (mp[i / 2]);
    }
}
