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
    let qo = [], qc = []
    qo.push(original)
    qc.push(cloned)
    while (qo.length != 0) {
        original = qo.shift()
        cloned = qc.shift()
        if (original == target)
            return cloned
        if (original.left)
            qo.push(original.left)
        if (original.right)
            qo.push(original.right)
        if (cloned.left)
            qc.push(cloned.left)
        if (cloned.right)
            qc.push(cloned.right)
    }
    return null
};
