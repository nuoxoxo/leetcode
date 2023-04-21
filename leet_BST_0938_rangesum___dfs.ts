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

function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
    if (!root)
        return 0
    let n: number = root.val
    if (n <= high && n >= low) {
        return n + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high)
    }
    return rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high)
};
