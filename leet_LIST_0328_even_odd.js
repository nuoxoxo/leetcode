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

var oddEvenList = function(head) {
    if (!head || !head.next)
        return head
    let odd = head
    let even = head.next
    let even_head = head.next
    while (odd.next && even.next) {
        odd.next = even.next
        even.next = odd.next.next
        odd = odd.next
        even = even.next
    }
    odd.next = even_head
    return head
};
