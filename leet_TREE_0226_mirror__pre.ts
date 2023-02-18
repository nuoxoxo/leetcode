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

function invertTree(node: TreeNode | null): TreeNode | null {
    if (!node)
        return node
    let temp = node.left
    node.left = node.right
    node.right = temp
    invertTree(node.left)
    invertTree(node.right)
    return node
};
