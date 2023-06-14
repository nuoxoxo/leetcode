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

function minDiffInBST(root: TreeNode | null): number {
    let dq = [root]
    let n = []
    while (dq.length) {
        let node = dq.shift()
        n.push(node.val)
        if (node.left) {
            dq.push(node.left)
        }
        if (node.right) {
            dq.push(node.right)
        }
    }

    let i = -1
    let res = Number.MAX_SAFE_INTEGER
    n.sort((a, b) => {return b - a})
    while (++i < n.length - 1) {
        let diff = n[i] - n[i + 1]
        res = res > diff ? diff : res 
    }
    return res
};
