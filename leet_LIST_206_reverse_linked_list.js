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

var reverseList = function(head) {
    if (head == null)
        return null
    prev = null
    next = null
    self = head
    while (self) {
        next = self.next
        self.next = prev
        prev = self
        self = next
    }
    return prev
};
