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

var invertTree = function(node) {
    if (!node)
        return null
    invertTree(node.left)
    invertTree(node.right)
    let temp = node.left
    node.left = node.right
    node.right = temp
    return node
};
