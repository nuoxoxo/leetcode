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

function countNodes(root: TreeNode | null): number {
    if ( !root ) {
        return 0
    }
    let D: TreeNode[] = [ root ]
    let res: number = 0
    while (D.length) {
        let i = -1
        while ( ++i < D.length ) {
            let node: TreeNode = D.shift()
            if (node.left) {
                D.push(node.left)
            }
            if (node.right) {
                D.push(node.right)
            }
            ++res
        }
    }
    return res
};
