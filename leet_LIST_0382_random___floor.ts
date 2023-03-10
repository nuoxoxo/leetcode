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

class Solution {
    ptr : ListNode | null;
    constructor(head: ListNode | null) {
        this.ptr = head
    }

    getRandom(): number {
        let p = this.ptr
        let a = []
        while (p) {
            a.push(p.val)
            p = p.next
        }
        return a[Math.floor(Math.random() * a.length)]
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(head)
 * var param_1 = obj.getRandom()
 */
