

function sortedArrayToBST(nums: number[]): TreeNode | null {
    return make_tree(nums, 0, nums.length - 1)
};

function make_tree(n: number[], L: number, R: number): TreeNode | null {
    if (L > R)
        return null
    let mid = Math.floor((L + R) / 2)
    let node = new TreeNode(n[mid])
    node.left = make_tree(n, L, mid - 1)
    node.right = make_tree(n, mid + 1, R)
    return node
}

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
