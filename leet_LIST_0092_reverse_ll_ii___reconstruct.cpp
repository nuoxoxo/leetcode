
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        vector<int>     v;
        ListNode        *p;
        ListNode        *temp;
        ListNode        *dummy;

        dummy = new ListNode(0);
        p = head;
        while (p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        reverse(v.begin() + left - 1, v.begin() + right);
        p = dummy;
        for (int n: v)
        {
            temp = new ListNode(n);
            p->next = temp;
            p = p->next;
        }
        return (dummy->next);
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
