
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode    *self;
        ListNode    *prev;
        ListNode    *next;

        if (!head)
            return (NULL);
        next = NULL;
        prev = NULL;
        self = head;
        while (self)
        {
            next = self->next;
            self->next = prev;
            prev = self;
            self = next;
        }
        head = prev;
        return (head); /* or simply return prev */
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

