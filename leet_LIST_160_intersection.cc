/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B)
    {
        ListNode    *a, *b;

        a = A;
        b = B;
        while (a != b)
        {
            if (a)
                a = a->next;
            else
                a = B;
            if (b)
                b = b->next;
            else
                b = A;
        }
        return a;
    }
};
