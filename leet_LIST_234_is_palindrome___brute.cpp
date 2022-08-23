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
    bool isPalindrome(ListNode* head)
    {
        deque<int>      d;
        ListNode*       p;

        p = head;
        while (p)
        {
            d.push_front(p->val);
            p = p->next;
        }
        p = head;
        while (p && p->val == d.front())
        {
            d.pop_front();
            p = p->next;
        }
        return d.size() == 0;
    }
};
