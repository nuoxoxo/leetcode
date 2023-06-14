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

function getMinimumDifference(root: TreeNode | null): number {
    let d = [root]
    let n = []
    while (d.length) {
        let node = d.shift()
        n.push(node.val)
        if (node.left) {
            d.push(node.left)
        }
        if (node.right) {
            d.push(node.right)
        }
    }
    n.sort((a, b) => {return b - a})
    let i = -1
    let res = Number.MAX_SAFE_INTEGER
    while (++i < n.length - 1) {
        let diff = n[i] - n[i + 1]
        res = res > diff ? diff : res 
    }
    return res
};
