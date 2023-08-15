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

function partition(head: ListNode | null, x: number): ListNode | null {
    if (head == null) {
        return head
    }
    let L: number[] = []
    let R: number[] = []
    let p: ListNode
    let n: number

    p = head
    while (p) {
        n = p.val
        if (n < x) {
            L.push(n)
        } else {
            R.push(n)
        }
        p = p.next
    }

    p = head
    for (let i of L) {
        p.val = i
        p = p.next
    }
    for (let i of R) {
        p.val = i
        p = p.next
    }
    return head
};
