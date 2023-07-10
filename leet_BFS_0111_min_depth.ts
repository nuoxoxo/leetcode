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

function minDepth(root: TreeNode | null): number {
    if (!root)
        return 0
    
    let D: TreeNode[] = [root]
    let res = 0
    while (D.length) {
        ++res
        let len: number = D.length // level length
        // console.log(D, D.length)
        while (len) {
            let node: TreeNode = D.shift()
            if (!node.left && !node.right)
                return res
            if (node.left)
                D.push(node.left)
            if (node.right)
                D.push(node.right)
            --len
        }
    }
    return res
};
