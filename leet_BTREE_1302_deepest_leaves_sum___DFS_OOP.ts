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

function deepestLeavesSum(root: TreeNode | null): number {

    const depth = {
        value: 0
    };

    const res = {
        value: 0
    };

    DFS(root, res, depth, 0);
    return res.value;
};

function DFS(node: TreeNode | null, res: { value: number }, depth: { value: number }, level: number): void {
    if (!node)
        return;
    
    if (level === depth.value) {
        res.value += node.val;
    } else if (level > depth.value) {
        res.value = node.val;
        depth.value = level;
    }

    DFS(node.left, res, depth, level + 1);
    DFS(node.right, res, depth, level + 1);
}
