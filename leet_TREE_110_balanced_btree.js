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
 * @return {boolean}
 */

var isBalanced = function(node) {
    if (!node)
        return true
    return count_depth(node) > 0
};

var count_depth = function(node){
    if (!node)
        return 0
    let R = count_depth(node.right)
    let L = count_depth(node.left)
    if (R < 0 || L < 0)
        return -1
    if (Math.abs(L - R) > 1)
        return -1
    return 1 + Math.max(L, R)
}
