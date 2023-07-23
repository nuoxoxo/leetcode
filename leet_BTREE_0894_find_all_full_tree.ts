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

function allPossibleFBT(n: number): Array<TreeNode | null> {
    if (n == 1)
        return [ new TreeNode() ]
    if (n % 2 == 0)
        return []
    let res: TreeNode[] = []
    let i: number = 1
    while (i < n - 1) {
        let L: TreeNode[] = allPossibleFBT(i)
        let R: TreeNode[] = allPossibleFBT(n - i - 1)
        for (let l of L) {
            for (let r of R) {
                let node: TreeNode = new TreeNode()
                node.left = l
                node.right = r
                res.push(node)
            }
        }
        i += 2
    }
    return res
};
