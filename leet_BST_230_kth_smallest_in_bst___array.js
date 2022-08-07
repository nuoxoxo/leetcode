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
 * @param {number} k
 * @return {number}
 */

var kthSmallest = function(root, k) {
    nodes = []
    function iot(node) {
        if (node) {
            iot(node.left)
            nodes.push(node.val)
            iot(node.right)
        }
    }
    iot(root)
    return nodes[k - 1]
};
