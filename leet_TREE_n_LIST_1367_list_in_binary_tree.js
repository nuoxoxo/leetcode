/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {ListNode} head
 * @param {TreeNode} root
 * @return {boolean}
 */

var isSubPath = function(head, node) {
    function cmp(head, node) {
        if (!head)
            return true
        if (!node || node.val != head.val)
            return false
        return cmp(head.next, node.left) || cmp(head.next, node.right)
    }
    function dfs(head, node) {
        if (!node)
            return false
        if (cmp(head, node))
            return true
        return dfs(head, node.left) || dfs(head, node.right)
    }
    return dfs(head, node)
};
