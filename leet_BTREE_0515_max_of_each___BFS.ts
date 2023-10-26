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

function largestValues(root: TreeNode | null): number[] {
    if (root === null)
        return []
    let D: TreeNode[] = [root]
    let res: number[] = []
    while (D.length) {
        let len:number = D.length
        let temp:number = Number.MIN_SAFE_INTEGER
        while (len--) {
            let node: TreeNode = D.shift()
            temp = Math.max(temp, node.val)
            if (node.left)
                D.push(node.left)
            if (node.right)
                D.push(node.right)
        }
        res.push(temp)
    }
    return res
};
