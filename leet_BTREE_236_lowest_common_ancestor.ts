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

function lowestCommonAncestor( node : TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    if (!node || node == p || node == q)
        return node
    let left = lowestCommonAncestor(node.left, p, q)
    let right = lowestCommonAncestor(node.right, p, q)
    if (left && right)
        return node
    if (left)
        return left
    return right
};
