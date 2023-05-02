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

function isUnivalTree(root: TreeNode | null): boolean {
    let d = [root]
    let x = root.val
    while (d.length ^ 0) {
        let node = d.shift()
        if (node.val ^ x) {
            return false
        }
        if (node.left)
            d.push(node.left)
        if (node.right)
            d.push(node.right)
    }
    return true
};
