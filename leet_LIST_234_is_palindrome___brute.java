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
    public boolean isPalindrome(ListNode head)
    {
        Stack<Integer>  s;
        ListNode        node;

        s = new Stack<Integer>();
        node = head;
        while (node != null)
        {
            s.push(node.val);
            node = node.next;
        }
        node = head;
        while (node != null && !s.empty())
        {
            if (s.pop() != node.val)
                return false ;
            node = node.next;
        }
        return true;
    }
}
