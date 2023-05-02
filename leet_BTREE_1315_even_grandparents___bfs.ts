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

function sumEvenGrandparent(root: TreeNode | null): number {
    let res = 0
    let d = [root]
    while (d.length) {
        let node = d.shift()
        if (node.left) {
            d.push(node.left)
        }
        if (node.right) {
            d.push(node.right)
        }
        if (node.val % 2 == 0) {
            if (node.left) {
                if (node.left.left) {
                    res += node.left.left.val
                }
                if (node.left.right) {
                    res += node.left.right.val
                }
            }
            if (node.right) {
                if (node.right.left) {
                    res += node.right.left.val
                }
                if (node.right.right) {
                    res += node.right.right.val
                }
            }
        }
    }
    return res
};
