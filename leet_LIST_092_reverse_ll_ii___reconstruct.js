/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */

var reverseBetween = function(head, left, right) {
    let p = head
    let arr = []
    let dummy = new ListNode(0)
    while (p) {
        arr.push(p.val)
        p = p.next
    }
    let L = arr.slice(0, left - 1)
    let mid = arr.slice(left - 1, right)
    let R = arr.slice(right, arr.length)
    let arr2 = L.concat(mid.reverse())
    arr2 = arr2.concat(R)
    p = dummy
    for (let n of arr2) {
        let temp = new ListNode(n)
        p.next = temp
        p = p.next
    }
    return dummy.next
};
