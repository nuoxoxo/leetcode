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

//  hare and tortoise method cf. #876 middle of list

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode    *H, *T;

        if (!head || !head->next)
            return false ;
        H = T = head;
        while (H->next && H->next->next)
        {
            H = H->next->next;
            T = T->next;
            if (H == T)
                return true ;
        }
        return false ;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
