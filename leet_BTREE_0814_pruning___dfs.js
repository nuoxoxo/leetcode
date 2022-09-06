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
 * @return {TreeNode}
 */
var pruneTree = function(node) {
    if (node == null)
        return node
    node.left = pruneTree(node.left)
    node.right = pruneTree(node.right)
    if (node.left == null && node.right == null && node.val == 0)
        return null
    return node
};
