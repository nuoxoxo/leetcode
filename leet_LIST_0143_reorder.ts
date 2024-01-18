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

/**
 Do not return anything, modify head in-place instead.
 */
function reorderList(head: ListNode | null): void {
    if ( ! head || ! head.next || ! head.next.next) {
        return
    }
    const dq: ListNode[] = []
    let node = head
    let len = 0
    while ( node ) {
        dq.unshift(node)
        node = node.next
        len++
    }
    node = head
    let i = -1
    while (++i < Math.floor(len / 2)) {
        let new_node: ListNode = dq.shift()
        new_node.next = node.next
        node.next = new_node
        node = node.next.next
    }
    node.next = null
};
