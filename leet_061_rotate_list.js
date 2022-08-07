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
var rotateRight = function(head, k) {
    if (head == null)
        return head
    let tail = head
    
    let n = 1
    while (tail.next) {
        tail = tail.next
        ++n
    }
    k %= n
    if (k == 0)
        return head
    i = -1
    let piv = head
    while (++i < n - k - 1)
        piv = piv.next
    let res = piv.next
    piv.next = null
    tail.next = head
    return res
};

/*
[1,2]
0
[1]
0
[]
0
[1,2,3,4,5]
2
[0,1,2]
4
*/
