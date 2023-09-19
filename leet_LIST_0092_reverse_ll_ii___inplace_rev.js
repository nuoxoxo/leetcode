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
    if (!head)
        return head
    let left_end = null
    let self = head
    let i = 0
    while (++i < left) {
        left_end = self
        self = self.next
    }
    let mid_head = null
    let mid_end = self // ie. "prev" in reverse_linked_list
    let next = null
    while (self && i++ < right + 1) {
        next = self.next
        self.next = mid_head
        mid_head = self
        self = next
    }
    if (left_end) {
        left_end.next = mid_head
    } else {
        head = mid_head
    }
    mid_end.next = self
    return head
};
