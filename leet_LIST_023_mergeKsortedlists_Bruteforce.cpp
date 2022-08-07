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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty())  return NULL ;

        ListNode    *res = new ListNode(), *tmp = res ;
        vector<int> arr ;
        int         i, n;

        n = lists.size() ;
        i = -1;
        while (++i < n)
        {
            ListNode*   p;

            p = lists[i];
            while (p)
            {
                arr.push_back(p->val);
                p = p->next;
            }
        }
        if (arr.empty())    return NULL ;
        sort(arr.begin(), arr.end());
        res->val = arr[0];
        i = 0;
        n = arr.size();
        while (++i < n)
        {
            ListNode*   p = new ListNode();

            p->val = arr[i];
            tmp->next = p;
            tmp = tmp->next;
        }
        return res ;
    }
};
