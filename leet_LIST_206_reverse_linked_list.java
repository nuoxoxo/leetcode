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
    public ListNode reverseList(ListNode head)
    {
        ListNode    self;
        ListNode    next;
        ListNode    prev;

        if (head == null)
            return (null);
        prev = null;
        next = null;
        self = head;
        while (self != null)
        {
            next = self.next;
            self.next = prev;
            prev = self;
            self = next;
        }
        return prev;
    }
}
