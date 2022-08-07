/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} original
 * @param {TreeNode} cloned
 * @param {TreeNode} target
 * @return {TreeNode}
 */

var getTargetCopy = function(o, c, t) {
    if (!o)
        return o
    if (o == t)
        return c
    let node = getTargetCopy(o.left, c.left, t)
    if (node)
        return node
    return getTargetCopy(o.right, c.right, t)
};
