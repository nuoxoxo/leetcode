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

function reverseOddLevels(root: TreeNode | null): TreeNode | null {
    if (!root)
        return null
    let dq: TreeNode [] = [ root ]
    let line: number []
    let level: number = 0
    while (dq.length) {
        let kids: number[] = []
        let len: number = dq.length
        while (len--) {
            let node: TreeNode = dq.shift()
            if (level % 2) {
                node.val = line[len]
            }
            if (node.left) {
                dq.push(node.left)
                kids.push(node.left.val)
            }
            if (node.right) {
                dq.push(node.right)
                kids.push(node.right.val)
            }
        }
        ++level
        line = kids
    }
    return root
};
