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

// let res = 0

function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
    let res = 0;
    const order = (node: TreeNode | null) => {
        if (!node) {
            return;
        }
        let n: number = node.val
        if (n >= low && n <= high) {
            res += n
        }
        if (node.left) {
            order(node.left);
        }
        if (node.right) {
            order(node.right)
        }
    }
    order(root)
    return res
};

// # Wrong
// 
// function order(res: number, node: TreeNode | null, lo: number, hi: number) {
//     if (!node) {
//         return
//     }
//     let n = node.val
//     if (n <= hi && n >= lo)
//         res += n;
//     order(res, node.left, lo, hi)
//     order(res, node.right, lo, hi)
// };

