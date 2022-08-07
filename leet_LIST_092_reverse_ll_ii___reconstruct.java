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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode    dummy;
        ListNode    temp;
        ListNode    p;
        int[]       arr;
        int         size;
        int         L, R;
        int         n;
        int         i;

        size = 0;
        p = head;
        while (p != null && ++size != 0)
            p = p.next;
        arr = new int[size];

        // System.out.println(Arrays.toString(arr));

        i = -1;
        p = head;
        while (p != null && ++i != i - 1)
        {
            arr[i] = p.val;
            p = p.next;
        }

        // System.out.println(Arrays.toString(arr));

        R = right - 1;
        L = left - 1;
        while (L <= R)
        {
            n = arr[L];
            arr[L++] = arr[R];
            arr[R--] = n;
        }

        // System.out.println(Arrays.toString(arr));

        dummy = new ListNode(0);
        p = dummy;
        i = -1;
        while (++i < size)
        {
            temp = new ListNode(arr[i]);
            p.next = temp;
            p = p.next;
        }
        return (dummy.next);
    }
}
