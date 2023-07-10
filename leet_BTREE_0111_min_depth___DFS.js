/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

var minDepth = function(r) {
    if (!r)
        return 0
    if (!r.left)
        return 1 + minDepth(r.right)
    if (!r.right)
        return 1 + minDepth(r.left)
    return 1 + Math.min( minDepth(r.left), minDepth(r.right) )
};
