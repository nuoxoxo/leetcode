/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

var deleteMiddle = function(head) {
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
