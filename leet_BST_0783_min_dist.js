/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDiffInBST = function(root) {
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

function inorder(node, arr) {
    if (!node)
        return
    inorder(node.left, arr)
    arr.push(node.val)
    inorder(node.right, arr)
}
