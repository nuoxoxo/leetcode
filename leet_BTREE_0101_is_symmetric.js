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

var isSymmetric = function(root) {
    var helper = (L, R) => {
        if (L == null && R == null) {
            return true
        }
        if (L == null || R == null) {
            return false
        }
        return (L.val == R.val && helper(L.left, R.right) && helper(L.right, R.left))
    }
    if (root == null)
        return true
    return helper(root.left, root.right)
};

