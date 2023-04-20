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

function widthOfBinaryTree(root: TreeNode | null): number {
    if (root == null) {
        return 0
    }
    let res = 0
    // let e = [[root, 0]] // Wrong
    // let e = [[root, 0], ...] // Wrong
    let e = []
    e.push([root, 0])
    while (e.length) {
        let len = e.length
        let start = e[0][1] // width
        let end = e[e.length - 1][1]
        res = Math.max(res, end - start + 1)
        while (len--) {
            let node = e.shift()
            let idx = node[1] - start
            if (node[0].left != null) {
                e.push([node[0].left, idx * 2 + 1]);
            }
            if (node[0].right != null) {
                e.push([node[0].right, idx * 2 + 2])
            }
        }
    }
    return res
};
