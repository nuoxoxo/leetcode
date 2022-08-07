/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */

var mergeTrees = function(r1, r2) {
    if (!r1 && !r2)
        return null
    if (!r1)
        return r2
    if (!r2)
        return r1
    r1.val += r2.val
    r1.left = mergeTrees(r1.left, r2.left)
    r1.right = mergeTrees(r1.right, r2.right)
    return r1
};
