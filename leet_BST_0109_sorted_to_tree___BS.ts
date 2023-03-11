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
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function sortedListToBST(head: ListNode | null): TreeNode | null {
    let a = []
    let p = head
    while (p) {
        a.push(p.val)
        p = p.next
    }
    return make_tree(a, 0, a.length - 1)
};

function make_tree(a, L, R): TreeNode { // Ts
// var make_tree = function (a, L, R) { // Js
    if (L > R)
        return null
    let mid = Math.floor((R - L) / 2) + L
    let node = new TreeNode(a[mid])
    node.left = make_tree(a, L, mid - 1)
    node.right = make_tree(a, mid + 1, R)
    return node
}
