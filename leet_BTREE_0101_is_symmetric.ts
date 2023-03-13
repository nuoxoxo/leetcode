/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function isSymmetric(root: TreeNode | null): boolean {
    function helper(L: TreeNode | null, R: TreeNode | null): boolean {
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
