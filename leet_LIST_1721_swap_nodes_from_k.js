/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */

var swapNodes = function(head, k) {
    let p = head, left = head, right = head
    while (k > 1) {
        --k
        p = p.next
        left = left.next
    }
    while (p.next) {
        p = p.next
        right = right.next
    }
    let temp = right.val
    right.val = left.val
    left.val = temp
    return head
};
