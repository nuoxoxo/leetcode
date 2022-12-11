/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */

var leafSimilar = function(root1, root2) {
    let dfs_on_single_node = (node, arr) => {
        if (!node) {
            return
        }
        if (!node.left && !node.right) {
            arr.push(node.val)
            return
        }
        dfs_on_single_node(node.left, arr)
        dfs_on_single_node(node.right, arr)
    }
    let a1 = []
    let a2 = []
    dfs_on_single_node(root1, a1)
    dfs_on_single_node(root2, a2)
    if (a1.length !== a2.length) {
        return false
    }
    let i = -1
    while (++i < a1.length) {
        if (a1[i] !== a2[i]) {
            return false
        }
    }
    return true
};
