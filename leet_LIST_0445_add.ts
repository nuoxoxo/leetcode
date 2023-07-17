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

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {

    let L: number[] = []
    let R: number[] = []
    while (l1) {
        L.push(l1.val)
        l1 = l1.next
    }
    while (l2) {
        R.push(l2.val)
        l2 = l2.next
    }

    // let res: ListNode = new ListNode(0)
    let res: ListNode = null
    let carry = 0
    while (carry != 0 || L.length != 0 || R.length != 0) {
        let l = L.length == 0 ? 0 : L.pop()
        let r = R.length == 0 ? 0 : R.pop()
        let node = new ListNode( (l + r + carry) % 10 )
        carry = Math.floor( (l + r + carry) / 10 )
        node.next = res
        res = node
    }
    return res
};
