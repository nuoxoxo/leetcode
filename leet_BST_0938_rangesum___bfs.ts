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
    let dq = [root]
    let a = []
    let temp: TreeNode | null
    let n: number
    while (dq.length) {
        temp = dq.shift()
        n = temp.val
        if (n <= high && n >= low) {
            a.push(n)
        }
        if (temp.left) {
            dq.push(temp.left)
        }
        if (temp.right) {
            dq.push(temp.right)
        }
    }
    return a.reduce((t, n) => t + n);
};
