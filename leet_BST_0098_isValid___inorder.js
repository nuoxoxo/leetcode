
var isValidBST = function(root) {
    let n = []
    let i = 0
    inorder(root, n)
    while (++i < n.length)
        if (n[i - 1] >= n[i])
            return false
    return true
};

function    inorder(node, nums) {
    if (!node)
        return
    inorder(node.left, nums)
    nums.push(node.val)
    inorder(node.right, nums)
}

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
 * @return {boolean}
 */
