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

var sumNumbers = function(root) {
    var helper = function(node, curr) {
        if (node == null)
            return 0
        let res = curr * 10 + node.val
        if (node.left == null && node.right == null)
            return res
        return helper(node.left, res) + helper(node.right, res)
    }
    return helper(root, 0)
};
