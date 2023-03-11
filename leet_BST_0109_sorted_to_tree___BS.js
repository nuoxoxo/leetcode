
var sortedListToBST = function(head) {

    let a = []
    let p = head
    while (p) {
        a.push(p.val)
        p = p.next
    }

    return to_tree(a, 0, a.length - 1)

    function to_tree(a, L, R) {
        if (L <= R) {
            let mid = Math.floor((R - L) / 2) + L
            let temp = new TreeNode(a[mid])
            temp.left = to_tree(a, L, mid - 1)
            temp.right = to_tree(a, mid + 1, R)
            return temp
        }
        return null
    }
};


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
 * @return {TreeNode}
 */
