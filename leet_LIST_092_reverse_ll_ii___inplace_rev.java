/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right)
    {
        ListNode    left_list;
        ListNode    mid_list;
        ListNode    prev;
        ListNode    next;
        ListNode    self;
        int         i;

        if (head == null)
            return (head);
        i = 0;
        self = head;
        left_list = null;
        while (++i < left) /* 1st traversal */
        {
            left_list = self;
            self = self.next;
        }
        prev = null;
        mid_list = self;
        while (self != null && i < right + 1)
        {
            next = self.next;
            self.next = prev;
            prev = self;
            self = next;
            ++i;
        }
        if (left_list != null)
            left_list.next = prev; /* if 1st traversal did happen */
        else
            head = prev; /* 1st traversal did not happen, ie. only mid section is reversed */
        mid_list.next = self;
        return (head);
    }
}
