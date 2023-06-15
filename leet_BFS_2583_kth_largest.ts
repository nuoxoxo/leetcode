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

function kthLargestLevelSum(root: TreeNode | null, k: number): number {
    let D:TreeNode[] = [root]
    let res:number[] = []
    while (D.length) {
        let level:number = 0
        let len:number = D.length
        while (len--) {
            let node:TreeNode = D.shift()
            level += node.val
            if (node.left)
                D.push(node.left)
            if (node.right)
                D.push(node.right)
        }
        res.push(level)
    }
    let n:number = res.length
    if (n < k) {
        return -1
    }

    // res.sort((a, b) => {return b - a})
    // return res[k - 1]

    res.sort((a, b) => {return a - b})
    return res[n - k]

};
