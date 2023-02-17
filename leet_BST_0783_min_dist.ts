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

function minDiffInBST(root: TreeNode | null): number {
    let arr = new Array()
    inorder(root, arr)
    console.log(arr)
    let i = -1
    // let res = Number.MAX_SAFE_INTEGER
    let res = 2147483647
    while (++i < arr.length - 1) {
        let diff = arr[i + 1] - arr[i]
        res = Math.min(res, diff)
    }
    return res
};

function inorder(node: TreeNode | null, arr): null {
    if (!node)
        return
    inorder(node.left, arr)
    arr.push(node.val)
    inorder(node.right, arr)
}
