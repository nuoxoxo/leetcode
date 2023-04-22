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

function findMode(root: TreeNode | null): number[] {
    let dq = [root]
    let mp = new Object()
    while (dq.length) {
        let node = dq.shift()
        let n = node.val
        if (!mp.hasOwnProperty(n)) {
            mp[n] = 1
        } else {
            mp[n]++
        }
        if (node.left)
            dq.push(node.left)
        if (node.right)
            dq.push(node.right)
    }
    let vals = Object.values(mp)
    let max = Math.max(...vals)
    let res = []
    for (let [k, v] of Object.entries(mp)) {
        // console.log(k, v, max, v == max)
        if (v == max) {
            res.push(k)
        }
    }
    return res
};
