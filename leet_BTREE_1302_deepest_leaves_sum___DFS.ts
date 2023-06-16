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

let g_res:number, g_depth:number

function deepestLeavesSum(root: TreeNode | null): number {
    g_res = 0
    g_depth = 0
    DFS(root, 0)
    return g_res
};

function DFS(node: TreeNode | null, level: number): null {
    if (!node)
        return
    if (level == g_depth) {
        g_res += node.val
    } else if (level > g_depth) {
        g_res = node.val
        g_depth = level
    }
    ++level
    DFS(node.left, level)
    DFS(node.right, level)
}
