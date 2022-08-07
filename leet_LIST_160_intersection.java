/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

public class Solution {
    public ListNode getIntersectionNode(ListNode A, ListNode B)
    {
        ListNode    a = A, b = B;
        while (a != b)
        {
            if (a == null)
                a = B;
            else
                a = a.next;
            if (b == null)
                b = A;
            else
                b = b.next;
        }
        return a;
    }
}
