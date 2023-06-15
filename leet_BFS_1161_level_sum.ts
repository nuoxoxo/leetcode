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

function maxLevelSum(root: TreeNode | null): number {
    if (!root)
        return 0
    let dq:TreeNode[] = [root]
    let record = Number.MIN_SAFE_INTEGER
    let level:number = 0
    let res:number = 0
    while (dq.length) {
        ++level
        let curr:number = 0
        let len:number = dq.length
        while (len--) {
            let node:TreeNode = dq.shift()
            curr += node.val
            if (node.left) {
                dq.push(node.left)
            }
            if (node.right) {
                dq.push(node.right)
            }
        }
        if (curr > record) {
            res = level
        }
        record = Math.max(curr, record)
    }
    return res
};
