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

function zigzagLevelOrder(root: TreeNode | null): number[][] {
    if (!root) return []
    let D = [root]
    let r = []
    let count = 0
    while (D.length != 0) {
        let size = D.length
        let temp = []
        while (--size > -1) {
            let node = D.shift()
            temp.push(node.val)
            if (node.left)
                D.push(node.left)
            if (node.right)
                D.push(node.right)
        }
        if (count % 2 ^ 0) {
            r.push(temp.reverse())
        } else {
            r.push(temp)
        }
        ++count
    }
    return r
};
