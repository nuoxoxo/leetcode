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

function isValidBST(root: TreeNode | null): boolean {
    let n: number[] = []
    inorder(root, n)
    let i = 0
    while (++i < n.length) {
        if (n[i - 1] >= n[i])
            return false
    }
    return true
};

function inorder(node: TreeNode | null, res: number[]) {
    if (!node)
        return
    inorder(node.left, res)
    res.push(node.val)
    inorder(node.right, res)
}
