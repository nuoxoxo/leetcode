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
    ListNode* partition(ListNode* head, int x)
    {
        vector<int> L;
        vector<int> R;
        ListNode    *p;
        int         n;

        if (!head)
            return (head);

        p = head;
        while (p)
        {
            n = p->val;
            if (n < x)
                L.push_back(n);
            else
                R.push_back(n);
            p = p->next;
        }
        p = head;
        for (int i: L)
        {
            p->val = i;
            p = p->next;
        }
        for (int i: R)
        {
            p->val = i;
            p = p->next;
        }
        return head ;
    }
};

