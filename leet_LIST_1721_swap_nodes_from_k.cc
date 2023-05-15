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

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode    *p, *L, *R;

        L = R = p = head;
        
        while (k != 1)
        {
            p = p->next;
            L = L->next;
            --k;
        }
        while (p->next)
        {
            p = p->next;
            R = R->next;
        }

        int tmp = L->val;
        L->val = R->val;
        R->val = tmp;
        return head;
    }
};
