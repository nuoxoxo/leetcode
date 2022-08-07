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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        map<int, ListNode*> mp;
        ListNode            *p;
        int                 i;
        
        i = 1;
        p = head;
        while (p)
        {
            ListNode *temp;
            temp = p;
            mp[i] = temp;
            p = p->next;
            ++i;
        }
        i -= n;
        if (i < 0)
            return (NULL);
        if (i == 1)
            head = head->next;
        else
            mp[i - 1]->next = mp[i + 1];

        return (head);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
