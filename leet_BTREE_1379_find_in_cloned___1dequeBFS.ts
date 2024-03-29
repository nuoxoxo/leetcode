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

function getTargetCopy(original: TreeNode | null, cloned: TreeNode | null, target: TreeNode | null): TreeNode | null {
    if (!original)
        return null
    if (original == target)
        return cloned
    let dq = []
    dq.push(cloned)
    while (dq.length != 0) {
        cloned = dq.shift()
        if (cloned.val == target.val)
            return cloned
        if (cloned.left)
            dq.push(cloned.left)
        if (cloned.right)
            dq.push(cloned.right)
    }
    return null
};
