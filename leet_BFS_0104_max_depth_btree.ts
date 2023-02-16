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

function maxDepth(root: TreeNode | null): number {
    if (root == null)
        return 0
    let arr = [root]
    let res = 0;
    while (arr.length !== 0) {
        let len = arr.length
        while (--len > -1) {
            let node = arr.shift()
            if (node.left)
                arr.push(node.left)
            if (node.right)
                arr.push(node.right)
        }
        ++res;
    }
    return res;

};
