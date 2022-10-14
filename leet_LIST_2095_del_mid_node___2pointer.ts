/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function deleteMiddle(head: ListNode | null): ListNode | null {
    if (!head || !head.next)
        return null
    let f = head
    let s = head
    let p
    while (f && f.next) {
        p = s
        s = s.next
        f = f.next.next
    }
    p.next = p.next.next
    return head
};
