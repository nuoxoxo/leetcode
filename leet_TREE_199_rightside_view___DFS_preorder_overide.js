var rightSideView = function(root) {
    this.res = []
    dfs(this.res, 1, root)
    return res
};

var dfs = function(res, level, node) {
    if (!node)
        return
    if (res.length < level)
        res.push(node.val)
    else
        res[level - 1] = node.val
    ++level
    dfs(res, level, node.left)
    dfs(res, level, node.right)
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
 * @return {number[]}
 */
