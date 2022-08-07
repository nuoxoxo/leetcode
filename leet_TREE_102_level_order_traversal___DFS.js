
var levelOrder = function(root) {
    if (!root)
        return []
    let res = []
    dfs(res, root, 0)
    return res
};

function dfs(res, node, level) {
    if (!node)
        return
    if (res.length == level)
        res.push([])
    res[level].push(node.val)
    dfs(res, node.left, level + 1)
    dfs(res, node.right, level + 1)
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
 * @return {number[][]}
 */
