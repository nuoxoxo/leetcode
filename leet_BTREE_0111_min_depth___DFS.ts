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

function minDepth(/* root */ node: TreeNode | null): number {
    if (!node)
        return 0
    if (!node.left)
        return 1 + minDepth(node.right)
    if (!node.right)
        return 1 + minDepth(node.left)
    return 1 + Math.min(minDepth(node.left), minDepth(node.right))
};
