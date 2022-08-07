/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */

var getIntersectionNode = function(A, B) {
    let a = A
    let b = B
    while (a != b) {
        if (a) {
            a = a.next
        } else {
            a = B
        }
        if (b) {
            b = b.next
        } else {
            b = A
        }
    }
    return a
};
