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

function reverseList(head: ListNode | null): ListNode | null {
    let self: ListNode, 
        prev: ListNode, 
        next: ListNode
    if (!head) {
        return null
    }
    next = null
    prev = null
    self = head
    while (self) {
        next = self.next
        self.next = prev
        prev = self
        self = next
    }
    head = prev
    return head

};
