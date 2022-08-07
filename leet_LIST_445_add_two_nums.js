/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */

var addTwoNumbers = function(a, b) {
    let head = null
    let carry = 0
    let s1 = []
    let s2 = []
    while (a) {
        s1.push(a.val)
        a = a.next
    }
    while (b) {
        s2.push(b.val)
        b = b.next
    }
    while (s1.length != 0 || s2.length != 0 || carry != 0) {
        let node = new ListNode(9)
        let n1 = s1.length != 0 ? s1.pop() : 0
        let n2 = s2.length != 0 ? s2.pop() : 0
        let temp = carry + n1 + n2
        node.val = temp % 10
        node.next = head
        head = node
        carry = Math.floor(temp / 10)
    }
    return head
};
