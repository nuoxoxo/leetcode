/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode *self;
    struct ListNode *next;
    struct ListNode *prev;

    if (!head)
        return (NULL);
    prev = NULL;
    next = NULL;
    self = head;
    while (self)
    {
        next = self->next;
        self->next = prev;
        prev = self;
        self = next;
    }
    head = prev;
    return (head);
}
