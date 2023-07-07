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

function mergeNodes(head: ListNode | null): ListNode | null {
    let L: ListNode | null = head
    let R: ListNode | null = head.next
    let temp: number = 0
    while (R) {
        if (R.val === 0) {
            L = L.next
            L.val = temp
            temp = 0
        } else {
            temp += R.val
        }
        R = R.next
    }
    L.next = null
    return head.next
};
