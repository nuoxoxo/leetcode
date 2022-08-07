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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode    *left_list;
        ListNode    *mid_list;
        ListNode    *prev;
        ListNode    *next;
        ListNode    *self;
        int         i;

        if (!head)
            return (head);
        i = 0;
        self = head;
        left_list = NULL;
        while (++i < left)
        {
            left_list = self;
            self = self->next;
        }
        prev = NULL; /* more accuate but w/o this line still works */
        mid_list = self;
        while (self && i < right + 1)
        {
            next = self->next;
            self->next = prev;
            prev = self;
            self = next;
            ++i;
        }
        if (left_list)
            left_list->next = prev;
        else
            head = prev;
        mid_list->next = self;
        return (head);
    }
};
