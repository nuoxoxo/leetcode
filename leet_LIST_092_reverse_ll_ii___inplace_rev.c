/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    //struct ListNode     *right_list; // no use eventually
    struct ListNode     *left_list;
    struct ListNode     *mid_list;
    struct ListNode     *prev;
    struct ListNode     *next;
    struct ListNode     *self;
    int                 i;

    if (head == NULL)
        return (head);
    i = 0;
    self = head;
    left_list = NULL;
    while (++i < left) /* 1st traversal */
    {
        left_list = self;
        self = self->next;
    }
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
        left_list->next = prev; /* if 1st traversal did happen */
    else
        head = prev; /* 1st traversal did not happen, ie. only mid section is reversed */
    mid_list->next = self;
    return (head);
}
