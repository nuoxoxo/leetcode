/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */

var sortedArrayToBST = function(nums) {
    let n = nums.length
    // if (n == 0)
    //     return null
    // if (n == 1)
    //     return new TreeNode(nums[0])
    return make_tree(nums, 0, n - 1)
};

function make_tree(nums, L, R) {
    if (L > R)
        return null
    let mid = Math.floor((R - L) / 2) + L
    let node = new TreeNode(nums[mid])
    node.left = make_tree(nums, L, mid - 1)
    node.right = make_tree(nums, mid + 1, R)
    return node
}
